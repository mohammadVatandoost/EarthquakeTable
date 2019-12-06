#include "sensorslist.h"

SensorsList::SensorsList(QObject *parent) : QObject(parent)
{

}

void SensorsList::addSensor(Sensor newSensor)
{
//    emit preItemAppended();
    sensorItems.append(newSensor);
//    emit postItemAppended();
}

void SensorsList::setSensorData(SensorRx *data)
{
  if(data->sensorId < sensorItems.size()) {
   sensorItems[data->sensorId].lastData = data->x;
   double tempDateTime = QDateTime::currentMSecsSinceEpoch();
   sensorItems[data->sensorId].addData(tempDateTime, data->x);
  } else {
      cout<< "err setSensorData: sensor id not valid:"<<data->sensorId<<endl;
  }
}

bool SensorsList::isNewId(uint8_t id)
{
    if(id < sensorItems.size()) {
        return false;
    }
    return true;
}
