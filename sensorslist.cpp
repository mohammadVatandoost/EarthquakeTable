#include "sensorslist.h"

SensorsList::SensorsList(QObject *parent) : QObject(parent)
{

}

void SensorsList::addSensor(Sensor newSensor)
{
//    emit preItemAppended();
//    testBug.append(newSensor.lastData);
//    Sensor2 temp; temp.lastData = newSensor.lastData;
    sensorItems.append(newSensor);
//    emit postItemAppended();
}

void SensorsList::setSensorData(SensorRx *data)
{
  if(data->sensorId < sensorItems.size()) {
   sensorItems[data->sensorId].lastData = data->x;
   double tempDateTime = QDateTime::currentMSecsSinceEpoch();
   sensorItems[data->sensorId].addData(tempDateTime, data->x);
   sensorItems[data->sensorId].lastData = data->x;
  } else {
      cout<< "err setSensorData: sensor id not valid:"<<data->sensorId<<endl;
  }
}

QString SensorsList::getSensorInfo(int sensorId)
{
    if(sensorId < sensorItems.size()) {
        return  sensorItems[sensorId].sensorInfo;
    } else {
        cout<< "err getSensorInfo: sensor id not valid:"<<sensorId<<endl;
        return "off";
    }
}

void SensorsList::setSensorInfo(int sensorId, QString temp)
{
    if(sensorId < sensorItems.size()) {
        sensorItems[sensorId].sensorInfo = temp;
    } else {
        cout<< "err setSensorInfo: sensor id not valid:"<<sensorId<<endl;
    }
}

double SensorsList::getSensorData(int sensorId)
{
    if(sensorId < sensorItems.size()) {
        return  sensorItems[sensorId].lastData;
    } else {
        cout<< "err getSensorData: sensor id not valid:"<<sensorId<<endl;
        return 255255;
    }
}

bool SensorsList::isNewId(uint8_t id)
{
    if(id < sensorItems.size()) {
        return false;
    }
    return true;
}
