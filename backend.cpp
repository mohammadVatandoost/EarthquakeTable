#include <QtCharts/QXYSeries>
#include <QtCharts/QAreaSeries>
#include "backend.h"

Q_DECLARE_METATYPE(QAbstractSeries *)
Q_DECLARE_METATYPE(QAbstractAxis *)
Q_DECLARE_METATYPE(QDateTimeAxis *)


Backend::Backend(QObject *parent) : QObject(parent)
{
    if(!QDir("Data").exists()) {
        QDir().mkdir("Data");
    } else {
        cout<<"folderData exits"<<endl;
    }
    serial = new QSerialPort(this);
    serial->close();
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    // timer for connection check
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    timer->start(1000);
    generalData = jsonStoring.getGeneralData();
}

void Backend::updateChart(QAbstractSeries *chartSeries, int floorNum)
{
  if(generalData.floor[floorNum] < mList->sensorItems.size() && -1 < floorNum) {
//      cout<< "updateChart floor: "<< floorNum << ", floor sensor:"<<generalData.floor[floorNum] <<endl;
      if(axisXTimes[floorNum]) {
//          cout<< "update axisXTimes"<<endl;
          axisXTimes[floorNum]->setMin(QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch()-60000));
          axisXTimes[floorNum]->setMax(QDateTime::currentDateTime());
      }
    if (chartSeries) {
        QXYSeries *xySeries = static_cast<QXYSeries *>(chartSeries);
//        qDebug()<< "chart update:"<< chartSeries->name() << ", data size:" << xySeries->points().size() <<endl;
//        QVector<QPointF> points = mList->sensorItems[sensorId].dataAccX;
        xySeries->replace(mList->sensorItems[generalData.floor[floorNum]].dataAccXChart);
    }
  } else {
      cout << "sensor id is not valid, floor:" << floorNum;
  }
}

void Backend::setAxisXTime(QDateTimeAxis *axis, int num) {
    if(num < chartsNumber) {
        axisXTimes[num] = axis;
        axisXTimes[num]->setMin(QDateTime::currentDateTime());
        axisXTimes[num]->setMax(QDateTime::currentDateTime().addSecs(60));
    } else {
        qDebug()<< "chart number is not valid:"<<num ;
    }
}

void Backend::decodePacket(QByteArray data)
{
    if(data.size() > 2) {
        uint32_t sum=0;
        for(int i=0; i<data.size()-1; i++) {
            sum = sum + ((uint8_t)data[i]);
        }
        if( sum % 256 == ((uint8_t)data[data.size()-1]) ) {
          uint8_t packetCode = ((uint8_t)data[0]);
          data.remove(data.size()-1,1);
          data.remove(0,1);
          if(packetCode == SensorRxPkt) {
              getSensorPkt(data);
          } else if (packetCode == MotorSpeedRxPkt) {
             getMotorSpeedPkt(data);
          } else if (packetCode == TorqueRxPkt) {
              getTorquePkt(data);
          } else if (packetCode == AckRxPkt) {
              getSegmentAckPkt(data);
          }
        } else {
            cout <<unsigned(((uint8_t)data[0])) << ": " << unsigned(static_cast<uint8_t>(data[data.size()-1])) << " checsum is wrong " << unsigned(((uint8_t)sum%256)&0xff)  << endl;
        }
    }
}

void Backend::getSensorPkt(QByteArray data)
{
    if(data.size() == sizeof(struct SensorRx)) {

     SensorRx *m = reinterpret_cast<SensorRx*>(data.data());
//     cout<< "Get sensor paket:"<< m->sensorId <<" : "<< m->x <<endl;
      if(mList->isNewId(m->sensorId)) {
            Sensor temp;
            temp.sensorNumber =  m->sensorId;
            temp.lastData = m->x;
            temp.max = m->x;
            temp.min = m->x;
            mList->addSensor(temp);
//            testBug.append(m->x);
      } else {
             mList->setSensorData(m);
      }

    } else {
        cout<< "getSensorPkt "<< data.size() << " must be "<<sizeof(struct SensorRx);
    }
}

void Backend::getMotorSpeedPkt(QByteArray data)
{
    if(data.size() == sizeof(struct MotorSpeedRx)) {
     MotorSpeedRx *m = reinterpret_cast<MotorSpeedRx*>(data.data());
//     cout<< "Get MotorSpeedRx paket:"<< m->frq <<endl;
     motorSpeed = m->frq;
    } else {
        cout<< "getMotorSpeedPkt "<< data.size() << " must be "<<sizeof(struct MotorSpeedRx);
    }
}

void Backend::getTorquePkt(QByteArray data)
{
    if(data.size() == sizeof(struct TorqueRx)) {
     TorqueRx *m = reinterpret_cast<TorqueRx*>(data.data());
     cout<< "Get TorqueRx paket:"<< m->torque <<endl;
     generalData.torque = m->torque;
     jsonStoring.storeGeneralData(generalData);
    } else {
        cout<< "getTorquePkt "<< data.size() << " must be "<<sizeof(struct TorqueRx);
    }
}

void Backend::getSegmentAckPkt(QByteArray data)
{
    if(data.size() == sizeof(struct AckRx)) {
     AckRx *m = reinterpret_cast<AckRx*>(data.data());
     cout<< "Get AckRxPkt paket:"<< m->packetId <<endl;
     sendSimulationData(m->packetId);
    } else {
        cout<< "getTorquePkt "<< data.size() << " must be "<<sizeof(struct TorqueRx);
    }
}

void Backend::sendConfig(ConfigTx temp)
{
    uint32_t sum = 0;
    char* dataBytes = static_cast<char*>(static_cast<void*>(&temp));
    for(int i=0; i<sizeof(struct ConfigTx); i++) {
        sum = sum + ((uint8_t)dataBytes[i]);
    }
    QString packet = "*@" ;
    QByteArray tx_data; tx_data.append(packet);
    serial->write(tx_data);
    serial->write(dataBytes, sizeof(struct ConfigTx));
    uint8_t checkSum= (uint8_t)sum%256;//reinterpret_cast<uint8_t>(sum%256);
//    cout<< " checksum: "<< unsigned(checkSum&0xff)<<endl;
    QByteArray checkSumByte;
    checkSumByte.append(checkSum);
    serial->write(checkSumByte);
}

void Backend::runSimulation()
{
  if(counterForSending < 3) {
      flagStartButton = true;
  } else if(dataSegments.size()>0) {
    ConfigTx temp;
    temp.mode = RUN;
    temp.loopTime = 20;
    sendConfig(temp);
  } else {
      cout<< "there is no file"<<endl;
  }
}

void Backend::sendSimulationData(int packetId)
{
    cout<< "sendSimulationData : "<< packetId << ", " << dataSegments.size() <<endl;
  for(int i=packetId; i<dataSegments.size();i++) {
      sendDataSegment(dataSegments[i]);
  }
  counterForSending = 0;
}

QString Backend::getErrorMessage()
{
    QString temp = errorMessage;
    errorMessage = "";
    return errorMessage;
}

void Backend::sendDataSegment(DataSegment temp)
{
    uint32_t sum = FileTxPkt;
    uint8_t packetCode = FileTxPkt;
    char* dataBytes = static_cast<char*>(static_cast<void*>(&temp));
    for(int i=0; i<sizeof(struct DataSegment); i++) {
        sum = sum + ((uint8_t)dataBytes[i]);
    }
    QString packet = "*@" ;
    QByteArray tx_data;
    tx_data.append(packet);
    serial->write(tx_data);
    QByteArray packetCodeByte;
    packetCodeByte.append(packetCode);
    serial->write(packetCodeByte);
    serial->write(dataBytes, sizeof(struct DataSegment));
    uint8_t checkSum= (uint8_t)sum%256;//reinterpret_cast<uint8_t>(sum%256);
    cout<<sizeof(struct DataSegment) << " sendDataSegment checksum: "<< unsigned(checkSum&0xff)<<endl;
    QByteArray checkSumByte;
    checkSumByte.append(checkSum);
    serial->write(checkSumByte);
}

void Backend::recieveSerialPort()
{
    QByteArray data;
    data = serial->readAll();

//    QString temp3;temp3.append(data);
//    qDebug()<< temp3;
    for(int i=0; i< data.size(); i++) {
//        cout<< unsigned(data[i]&0xFF) << ",";
        if(data[i] == '*' && recieveState == 0) {
            recieveState = recieveState + 1;
            decodePacket(dataBuf);
        } else if( recieveState == 1) {
            if(data[i] == '@') {
              recieveState = recieveState + 1;
            } else {
                recieveState = 0;
            }
            dataBuf.clear();
        } else if(recieveState == 2) {
            uint8_t packetCode = static_cast<uint8_t>(data[i]);
            if(packetCode == SensorRxPkt) {
                packetSize =  sizeof(struct SensorRx);
                dataBuf.append(data[i]);
                recieveState = recieveState + 1;
            } else if(packetCode == MotorSpeedRxPkt) {
                packetSize =  sizeof(struct MotorSpeedRx);
                dataBuf.append(data[i]);
                recieveState = recieveState + 1;
            } else if(packetCode == TorqueRxPkt) {
                packetSize =  sizeof(struct TorqueRx);
                dataBuf.append(data[i]);
                recieveState = recieveState + 1;
            } else if(packetCode == AckRxPkt) {
                packetSize =  sizeof(struct AckRx);
                dataBuf.append(data[i]);
                recieveState = recieveState + 1;
            }  else {
                cout<< " recieveSerialPort packet code is wrong: "<< unsigned(packetCode)<< endl;
                packetSize = 0;
                recieveState = 0;
                dataBuf.clear();
            }
        } else if(recieveState > 2){
            dataBuf.append(data[i]);
            recieveState = recieveState + 1;
            if( packetSize + 3 < recieveState) {
               recieveState = 0;
            }
        }
    }
}

void Backend::timerSlot()
{
   if(QSerialPortInfo::availablePorts().size()>0) {
    if(!serial->isOpen()) {
        Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
                   serial->setPortName(port.portName());
                   qDebug() << " portName : " << port.portName();
        }
//         serial->close();
        if(serial->open(QIODevice::ReadWrite)) {
//           serial->flush();
          connectState = true; qDebug() << " conndected : ";
          connect(serial, SIGNAL(readyRead()), this, SLOT(recieveSerialPort()));
        } else {
            connectState = false; qDebug() << "Not conndected : ";
            serial->close();
        }
    } else {
        if(counterForSending < 3) {
           counterForSending++;
           if(counterForSending == 2) {
               ConfigTx tempConfig;
               tempConfig.mode =CONFIG;
               tempConfig.loopTime = 10;
               sendConfig(tempConfig);
           }
           if(counterForSending == 3) {
               cout<< "go to run mode"<<endl;
              if(flagStartButton) {
                runSimulation();
              }
           }
        }
//        ConfigTx temp;
//        temp.mode = SendData;
//        sendConfig(temp);
//        DataSegment temp100;
//        temp100.packetId = 0;
//        temp100.data[0] = 1;temp100.data[1] = 1;
//        temp100.data[2] = 1;temp100.data[3] = 1;
//        temp100.data[4] = 1;temp100.data[5] = 1;
//        temp100.data[6] = 1;temp100.data[7] = 1;
//        temp100.data[8] = 1;temp100.data[9] = 0;
//        sendDataSegment(temp100);
//        counter++;
//        if(counter %3 == 0) {
//           colibrate();
//        } else if(counter %3 == 1) {
//            moveRight();
//        } else if(counter %3 == 2) {
//           runSimulation();
//        }
//        ConfigTx temp;
//        temp.mode = 40;
//        sendConfig(temp);


    }
   } else {
       serial->close();
//       connectState = false;qDebug() << "Disconndected : ";
   }

//   serial->write("hello");
//   if(mList->sensorItems.size() > 0) {
////       cout<< "test add data"<<endl;
//       SensorRx *temp = new SensorRx();
//       temp->sensorId = 0;
//       temp->x = 5;
//       mList->setSensorData(temp);
////       for(int i=0; i<mList->sensorItems[0].data.size(); i++) {
////           cout<< mList->sensorItems[0].data[i].x() << " : "<<  mList->sensorItems[0].data[i].y()<<endl ;
////       }
////       cout<<endl;
//   }

//   emit notifyInfoDataChanged();
}

void Backend::setSensorsList(SensorsList *sensorsList)
{
    qDebug()<< "set sensorList";
    mList = sensorsList;
}

void Backend::colibrate()
{
  ConfigTx temp;
  temp.mode = CALIBRATION;
  temp.loopTime = 20;
  sendConfig(temp);
}

void Backend::moveRight()
{
   ConfigTx temp;
   temp.mode = CONFIG;
   temp.move = MoveRight;
   temp.loopTime = 20;
   sendConfig(temp);
}

void Backend::moveLeft()
{
    ConfigTx temp;
    temp.mode = CONFIG;
    temp.move = MoveLeft;
    temp.loopTime = 20;
    sendConfig(temp);
}

void Backend::readFile(QString fileDirectory)
{
    fileAddress = fileDirectory;
    sendFileData();
}

void Backend::setSensorInfo()
{

}

QString Backend::getMotorSpeed()
{
    return QString::number(motorSpeed) + " rpm";
}

double Backend::getFloorData(int floorNum)
{
    if(generalData.floor[floorNum] < mList->sensorItems.size()) {
        return  mList->sensorItems[generalData.floor[floorNum]].lastData;
    } else {
//        cout<< "err getFloorData: sensor id not valid:"<<floorNum<<endl;
        return 255255;
    }
}

int Backend::getMaxValue(int floorNum)
{
    if(generalData.floor[floorNum] < mList->sensorItems.size()) {
        return  mList->sensorItems[generalData.floor[floorNum]].max+5;
    } else {
//        cout<< "err getFloorData: sensor id not valid:"<<floorNum<<endl;
        return 1000;
    }
}

int Backend::getMinValue(int floorNum)
{
    if(generalData.floor[floorNum] < mList->sensorItems.size()) {
        return  mList->sensorItems[generalData.floor[floorNum]].min-5;
    } else {
//        cout<< "err getFloorData: sensor id not valid:"<<floorNum<<endl;
        return -1000;
    }
}

void Backend::setFloorInfo(int floorNum, QString temp)
{
    if(temp == "off") {
        generalData.floor[floorNum] = offValue;
    } else {
        temp.replace("Ax", "");
        generalData.floor[floorNum] = temp.toInt()-1;
    }
    cout<< "setFloorInfo "<< floorNum << " : "<< generalData.floor[floorNum]<<endl;
}

QString Backend::getFloorInfo(int floorNum)
{
    if(generalData.floor[floorNum] == offValue) {
        cout<< "getFloorInfo "<< floorNum << " : "<< "off";
        return "off";
    } else {
        QString temp = "Ax" + QString::number(generalData.floor[floorNum]+1);
        cout<< "getFloorInfo "<< floorNum << " : "<< temp.toStdString()<<endl;
        return temp;
    }
}

void Backend::setTimeStep(QString temp)
{
    temp.replace("ms", "");
    timeStep = temp.toInt();
}

void Backend::saveGroundMotion(QString temp)
{

}

void Backend::sendFileData()
{
    qDebug()<< "sendFileData";
    QString message;
    QVector<uint16_t> dataList;
    if(fileAddress.contains(".txt")) {
        fileAddress.replace("file://", "");
        qDebug()<< fileAddress;
        QFile file(fileAddress);
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            message = "File not exists" ;
            qDebug() << message;
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                for (QString item : line.split(" ")) {
                    if( myUtitlity.checkStringContainsNum(item.toUtf8().toStdString()) ) {
                            item.replace(" ", "");
//                            qDebug()<< item;
                            dataList.append(static_cast<uint16_t>(item.toDouble()*10000));
                    }
                }
            }
          file.close();

          if(dataList.size()>0) {
              ConfigTx temp;
              temp.mode = SendData;
              sendConfig(temp);
              dataSegments.clear();
              myUtitlity.delay_ms(1);
              cout<< "send" << dataList.size() << endl;
              int i=0;
              int packetId = 0;
              while (i<dataList.size()) {
                  DataSegment dataSegment;
                  dataSegment.packetId = packetId;
                  for(int j=0; j< MAX_SEG_DATA; j++) {
                      if(i<dataList.size()) {
                          dataSegment.data[j] = dataList[i];
                          i++;
                      } else {
                          dataSegment.data[j] = 0;
                      }
                  }
                  dataSegments.append(dataSegment);
                  packetId++;
              }
              cout<< "dataSegments:" << dataSegments.size() << endl;
              sendSimulationData(0);
          }

        }
    } else {
        message = "invalid file: does not contains .txt";
        qDebug() << message;
    }
}
