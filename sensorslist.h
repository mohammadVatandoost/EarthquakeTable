#ifndef SENSORSLIST_H
#define SENSORSLIST_H

#include <QObject>
#include "sensor.h"
#include "packet.h"

class SensorsList : public QObject
{
    Q_OBJECT
public:
    explicit SensorsList(QObject *parent = nullptr);
    bool setSensorItem(int index,Sensor &sensor);
    bool isNewId(uint8_t id);
//    QVector<Sensor> items();
    QVector<Sensor> sensorItems;
    void addSensor(Sensor newSensor);
    void setSensorData(SensorRx *data);

    Q_INVOKABLE QString getSensorInfo(int sensorId);
    Q_INVOKABLE void setSensorInfo(int sensorId, QString temp);
    Q_INVOKABLE double getSensorData(int sensorId);
signals:

public slots:
};

#endif // SENSORSLIST_H
