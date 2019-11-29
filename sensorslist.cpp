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
