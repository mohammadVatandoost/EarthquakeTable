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
}

void Backend::updateChart(QAbstractSeries *chartSeries, int sensorId)
{
  if(sensorId < mList->sensorItems.size() && -1 < sensorId) {
      if(axisXTimes[sensorId]) {
          axisXTimes[sensorId]->setMin(QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch()-60000));
          axisXTimes[sensorId]->setMax(QDateTime::currentDateTime());
      }
    if (chartSeries) {
        QXYSeries *xySeries = static_cast<QXYSeries *>(chartSeries);
//        qDebug()<< "chart update:"<< chartSeries->name() << ", data size:" << xySeries->points().size() <<endl;
        QVector<QPointF> points = mList->sensorItems[sensorId].data;
        xySeries->replace(points);

    }
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
           }
        } else {
            cout << ", " << unsigned(static_cast<uint8_t>(data[data.size()-1])) << " checsum is wrong " << sum%256  << endl;
        }
    }
}

void Backend::getSensorPkt(QByteArray data)
{
    if(data.size() == sizeof(struct SensorRx)) {
     SensorRx *m = reinterpret_cast<SensorRx*>(data.data());
      if(mList->isNewId(m->sensorId)) {
            Sensor temp;
            temp.sensorNumber =  m->sensorId;
            temp.lastData = m->x;
            mList->addSensor(temp);
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

    } else {
        cout<< "getMotorSpeedPkt "<< data.size() << " must be "<<sizeof(struct MotorSpeedRx);
    }
}

void Backend::getTorquePkt(QByteArray data)
{
    if(data.size() == sizeof(struct TorqueRx)) {
     TorqueRx *m = reinterpret_cast<TorqueRx*>(data.data());

    } else {
        cout<< "getTorquePkt "<< data.size() << " must be "<<sizeof(struct TorqueRx);
    }
}

void Backend::sendConfig()
{
    uint32_t sum = 0;
    ConfigTx temp;
    char* dataBytes = static_cast<char*>(static_cast<void*>(&temp));
    for(int i=1; i<sizeof(struct ConfigTx); i++) {
        sum = sum + ((uint8_t)dataBytes[i]);
    }
    QString packet = "*@" ;
    QByteArray tx_data; tx_data.append(packet);
    serial->write(tx_data);
    serial->write(dataBytes, sizeof(struct ConfigTx));
    uint8_t checkSum= (uint8_t)sum%256;//reinterpret_cast<uint8_t>(sum%256);
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
            }  else {
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
    mList = sensorsList;
}

void Backend::colibrate()
{

}

void Backend::moveRight()
{

}

void Backend::moveLeft()
{

}

void Backend::setSensorInfo()
{

}
