#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <QString>
#include <QVector>
#include <QVector2D>
#include <QPointF>
#include "myutitlity.h"

#define saveToFile  10000
#define averageNum  10
#define dataChartNum  600

using namespace std;

struct Sensor {
    uint8_t sensorNumber;
    uint8_t floor;  
    QString sensorInfo = "off";
    double lastData = 10.5;
    QVector<QPointF> dataAccX;
    QVector<QPointF> dataAccXChart;
    int averageCounter=0;
    double averageSum = 0;
    double averageTime =0;
    int max = 1000;
    int min = 1000;

    void addData(double time, double value) {
        QPointF temp(time,value);
        if(max < value) {
            max = value;
        } else if(min > value) {
            min = value;
        }
        // for averaging chart
        averageSum = averageSum + value;
        averageCounter++;
        if(averageCounter == 5) {
            averageTime = time;
        }
        if(averageCounter == 10) {
            QPointF temp2(averageTime, averageSum/averageCounter);
            dataAccXChart.append(temp2);
            averageSum = 0; averageCounter = 0;
            if(dataAccXChart.size() > (dataChartNum*2)) {
                dataAccXChart.erase(dataAccXChart.begin(), dataAccXChart.begin()+ dataChartNum);
            }
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
