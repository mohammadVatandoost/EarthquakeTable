#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <QString>
#include <QVector>
#include <QPointF>
#include "myutitlity.h"

#define saveToFile  1000

using namespace std;

struct Sensor {
    uint8_t sensorNumber;
    uint8_t floor;
    QVector<QPointF> data;
    double lastData;

    void addData(double time, double value) {
        QPointF temp(time,value);
        data.append(temp);
        if(data.size() > saveToFile*2) {
            cout<< "store to csv file"<<endl;
            saveSensorDataToCSVFile(&data, sensorNumber, "Ax", saveToFile);
        }
    }
};

#endif // SENSOR_H
