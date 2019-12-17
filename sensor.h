#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <QString>
#include <QVector>
#include <QVector2D>
#include <QPointF>
#include "myutitlity.h"

#define saveToFile  10000

using namespace std;

struct Sensor2 {
    uint8_t sensorNumber;
    uint8_t floor;
    QString sensorInfo = "off";
    double lastData = 10.5;
};

struct Sensor {
    uint8_t sensorNumber;
    uint8_t floor;  
    QString sensorInfo = "off";
    double lastData = 10.5;
    QVector<QPointF> dataAccX;
    int max = 1000;
    int min = 1000;

    void addData(double time, double value) {
        QPointF temp(time,value);
        if(max < value) {
            max = value;
        } else if(min > value) {
            min = value;
        }
//        qDebug()<< time << " : "<< value;
        dataAccX.append(temp);
        if(dataAccX.size() > saveToFile*2) {
            cout<< "store to csv file"<<endl;
            saveSensorDataToCSVFile(&dataAccX, sensorNumber, "Ax", saveToFile);
        }
    }
};

#endif // SENSOR_H
