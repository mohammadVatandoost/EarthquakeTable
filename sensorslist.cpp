#include "sensorslist.h"

SensorsList::SensorsList(QObject *parent) : QObject(parent)
{
   Sensor sensor;
   sensor.sensorNumber = 0;
   addSensor(sensor);
   sensor.sensorNumber = 1;
   addSensor(sensor);
   sensor.sensorNumber = 2;
   addSensor(sensor);
   sensor.sensorNumber = 3;
   addSensor(sensor);
}

void SensorsList::addSensor(Sensor newSensor)
{
//    emit preItemAppended();
    sensorItems.append(newSensor);
//    emit postItemAppended();
}

void SensorsList::setSensorData(SensorRx *data)
{
   sensorItems[data->sensorId].lastData = data->x;
   double tempDateTime = QDateTime::currentMSecsSinceEpoch();
   sensorItems[data->sensorId].addData(tempDateTime, data->x);
}

bool SensorsList::isNewId(uint8_t id)
{
    if(id < sensorItems.size()) {
        return false;
    }
    return true;
}
