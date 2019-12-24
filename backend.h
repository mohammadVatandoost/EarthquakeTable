﻿#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include "QDebug"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QtCharts/QAbstractSeries>
#include <QTime>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts>
#include <iostream>
#include <QDir>
#include "generaldata.h"
#include "packet.h"
#include "sensorslist.h"
#include "jsonstoring.h"

#define chartsNumber 4

using namespace std;

QT_CHARTS_USE_NAMESPACE

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE void setSensorsList(SensorsList *sensorsList);
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void readFile(QString fileDirectory);
    Q_INVOKABLE void setSensorInfo();
    Q_INVOKABLE QString getMotorSpeed();
    Q_INVOKABLE double getFloorData(int floorNum);
    Q_INVOKABLE int getMaxValue(int floorNum);
    Q_INVOKABLE int getMinValue(int floorNum);
    Q_INVOKABLE void setFloorInfo(int floorNum, QString temp);
    Q_INVOKABLE QString getFloorInfo(int floorNum);
    Q_INVOKABLE void setTimeStep(QString temp);
    Q_INVOKABLE void saveGroundMotion(QString temp);
    void sendFileData();
    QString fileAddress;
    QSerialPort *serial;
    QString come_port;
    QTimer *timer;
    MyUtitlity myUtitlity;
    bool connectState = false;
    QByteArray dataBuf;
    uint16_t recieveState = 0;
    uint16_t packetSize = 0;
    GeneralData generalData;
    int motorSpeed = 0 ;
    void decodePacket(QByteArray data);
    void getSensorPkt(QByteArray data);
    void getMotorSpeedPkt(QByteArray data);
    void getTorquePkt(QByteArray data);
    void getSegmentAckPkt(QByteArray data);
    void sendConfig(ConfigTx temp);
    Q_INVOKABLE void runSimulation();
    int counter = 0;

//    QVector<double> testBug;
    // charts
    QDateTimeAxis* axisXTimes[chartsNumber];

    //for storing data
    JsonStoring jsonStoring;

    // for sending file
    int counterForSending = 0;
    QVector<DataSegment> dataSegments;
    void sendDataSegment(DataSegment temp) ;
    void sendSimulationData(int packetId);
    bool flagStartButton = false;
    int timeStep = 10;

    // for error report
    QString errorMessage = "";
    Q_INVOKABLE QString getErrorMessage();
    Q_INVOKABLE void visibleTimeAxis(int floorNum);

    // for colibrate
    QString colibrateName;
    Q_INVOKABLE void colibrate(QString name);
    void addToColibrate(int colibrateValue);
signals:

public slots:
    void updateChart(QAbstractSeries *chartSeries, int floorNum);

    void setAxisXTime(QDateTimeAxis *axis, int num);

private:
    SensorsList *mList;
private slots:
    void recieveSerialPort();
    void timerSlot();
};

#endif // BACKEND_H
