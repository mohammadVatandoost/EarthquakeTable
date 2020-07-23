#include "sensorslist.h"

SensorsList::SensorsList(QObject *parent) : QObject(parent)
{

}

void SensorsList::addSensor(Sensor newSensor)
{
    sensorItems.append(newSensor);
}

void SensorsList::setSensorData(SensorRx *data)
{
    if(data->sensorId < sensorItems.size()) {
       sensorItems[data->sensorId].lastData = data->y*3.9;
       if(data->x != 32767) {
           double tempDateTime = QDateTime::currentMSecsSinceEpoch();
           sensorItems[data->sensorId].addData(tempDateTime, data->y*3.9);
       }

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

bool SensorsList::isNewId(uint8_t id)
{
    if(id < sensorItems.size()) {
        return false;
    }
    return true;
}
