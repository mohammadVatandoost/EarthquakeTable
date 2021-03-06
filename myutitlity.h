#ifndef MYUTITLITY_H
#define MYUTITLITY_H

#include <iostream>
#include <sstream>      // std::stringstream
#include <QPointF>
#include <QVector>
#include <QDate>
#include <chrono>
#include <thread>
#include "csv.h"

using namespace std;

class MyUtitlity {
public:
    MyUtitlity() {}
    string numberToString(double num) {
        ostringstream ss;
        ss << num;
        return ss.str();
    }
    string numberToString(uint8_t num){
        ostringstream ss;
        ss << num;
        return ss.str();
    }
    string numberToString(uint16_t num){
        ostringstream ss;
        ss << num;
        return ss.str();
    }
    string numberToString(uint32_t num){
        ostringstream ss;
        ss << num;
        return ss.str();
    }
    string numberToString(int num){
        ostringstream ss;
        ss << num;
        return ss.str();
    }
    string numberToString(float num){
        ostringstream ss;
        ss << num;
        return ss.str();
    }

    bool checkStringContainsNum(string c) {
        return (
                c.find('0') != std::string::npos ||
                c.find('1') != std::string::npos ||
                c.find('2') != std::string::npos ||
                c.find('3') != std::string::npos ||
                c.find('4') != std::string::npos ||
                c.find('5') != std::string::npos ||
                c.find('6') != std::string::npos ||
                c.find('7') != std::string::npos ||
                c.find('8') != std::string::npos ||
                c.find('9') != std::string::npos
            );
    }

    void delay_ms(int time) {
        this_thread::sleep_for(chrono::milliseconds(time));
    }
};

inline void saveSensorDataToCSVFile(QVector<QPointF> *dataList, int sensorNumber, QString tempOrRes, int begin,  int end) {
    QVector<QStringList> dataStringList;
//    qDebug() << "begin :"<< begin << ", end:"<<end << ", dataList->size():"<< dataList->size();
    for(int j = begin; j<end; j++) {
        QStringList listRow;
        listRow.append( QString::number(dataList->at(j).x()));
        listRow.append( QString::number(dataList->at(j).y()));
        dataStringList.append(listRow);
    }
//    dataList->remove(0, n);
    dataList->remove(begin, end);
    QString dateTime = QDateTime::currentDateTime().toString();
    dateTime = dateTime.replace(":","_");
    appendDataToCSV(dataStringList, "./Data/sensor"+QString::number(sensorNumber)+"_"+tempOrRes+"_"+dateTime+".csv"); //"_"+QString::number(minuteBuff)+

}

#endif // MYUTITLITY_H
