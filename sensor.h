#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <QString>
#include <QVector>
#include <QVector2D>
#include <QPointF>
#include <iir/Butterworth.h>
#include "myutitlity.h"
//#include "Butterworth.h"

#define saveToFile  10000
#define averageNum  10
#define dataChartNum  600
#define filter_order 4

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
    // bandpass filter
//    Iir::Butterworth::BandPass<filter_order> f;
    Iir::Butterworth::BandPass<filter_order> *f;
    float f1 = 0;
    float f2 = 199;
    double sample_frequency = 200;
    double maxAccelarator = 0;
    Sensor() {
        f = new Iir::Butterworth::BandPass<filter_order>();
//        f.reset();
        qDebug() << "Sensor filter setup sample_frequency:"<<sample_frequency<<", f1:"<<f1<<", f2:"<<f2;
        f->setup(sample_frequency, (f1+f2)/2, f2-f1);
        double filteredValue = f->filter(10);
        f->reset();
        f->setup(sample_frequency, (f1+f2)/2, f2-f1);
    }
    void filterUpdate(double freq1, double freq2, double sample_frq){
//        sample_frequency = sample_frq;
        f1 = freq1; f2 = freq2;
        f->reset();
        f->setup(sample_frequency, (f1+f2)/2, f2-f1);
        qDebug() << "Sensor filter filterUpdate sample_frequency:"<<sample_frequency<<", f1:"<<f1<<", f2:"<<f2;


    }

    void addData(double time, double value) {
        QPointF temp(time,value);
        if(max < value) {
            max = value;
        } else if(min > value) {
            min = value;
        }
        // for averaging chart
        double filteredValue = f->filter(value);
//        qDebug() << value<<", "<< filteredValue;
        averageSum = averageSum + filteredValue; //value
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
