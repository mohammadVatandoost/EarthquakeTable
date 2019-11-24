#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <QString>
#include <QVector>
#include <QPointF>

using namespace std;

struct Sensor {
    uint8_t sensorNumber;
    uint8_t floor;
    QVector<QPointF> data;
    void addData(double time, double value) {
        QPointF temp(time,value);
        data.append(temp);
    }
};

#endif // SENSOR_H
