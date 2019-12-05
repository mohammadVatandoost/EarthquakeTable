#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include "QDebug"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QtCharts/QAbstractSeries>
#include <QTime>
#include <QtCharts/QDateTimeAxis>
#include <iostream>
#include <QDir>
#include "packet.h"
#include "sensorslist.h"

#define chartsNumber 4

using namespace std;

QT_CHARTS_USE_NAMESPACE

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE void setSensorsList(SensorsList *sensorsList);
    QSerialPort *serial;
    QString come_port;
    QTimer *timer;
    bool connectState = false;
    QByteArray dataBuf;
    uint16_t recieveState = 0;
    uint16_t packetSize = 0;
    void decodePacket(QByteArray data);
    void getSensorPkt(QByteArray data);
    void getMotorSpeedPkt(QByteArray data);
    void getTorquePkt(QByteArray data);
    // charts
    QDateTimeAxis* axisXTimes[chartsNumber];

signals:

public slots:
    void updateChart(QAbstractSeries *chartSeries, int sensorId);
    void setAxisXTime(QDateTimeAxis *axis, int num);

private:
    SensorsList *mList;
private slots:
    void recieveSerialPort();
    void timerSlot();
};

#endif // BACKEND_H
