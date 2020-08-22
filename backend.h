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
#include <QtCharts>
#include <iostream>
#include <QDir>
#include "generaldata.h"
#include "packet.h"
#include "sensorslist.h"
#include "jsonstoring.h"
#include "groundmotionlist.h"
#include "colibrateitemmodel.h"
#include <QStringListModel>

#define chartsNumber 4

using namespace std;

QT_CHARTS_USE_NAMESPACE

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);
    // set model lists
    Q_INVOKABLE void setSensorsList(SensorsList *sensorsList);
    Q_INVOKABLE void setGroundMotionList(GroundMotionList *tempList);
    Q_INVOKABLE void setColibrateItemModel(ColibrateItemModel *tempList);

    Q_INVOKABLE void stopMoving();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void readFile(QString fileDirectory, QString file_name);
    Q_INVOKABLE void setSensorInfo();
    Q_INVOKABLE QString getMotorSpeed();
    Q_INVOKABLE double getFloorData(int floorNum);
    Q_INVOKABLE int getMaxValue(int floorNum);
    Q_INVOKABLE int getMinValue(int floorNum);
    Q_INVOKABLE void setFloorInfo(int floorNum, QString temp);
    Q_INVOKABLE QString getFloorInfo(int floorNum);
    // for ground motion
    Q_INVOKABLE void setTimeStep(QString temp);
    Q_INVOKABLE int saveGroundMotion(QString temp);
    Q_INVOKABLE void removeGroundMotion(QString temp);
    Q_INVOKABLE QList<QString> getGroundMotions();
    Q_INVOKABLE QStringList getGroundMotionNames();
    Q_INVOKABLE void setSelectedGroundMotion(int temp);
    Q_INVOKABLE void sendFileData(int index);
    QString fileAddress, userFileName;

    Q_INVOKABLE void changePassword(QString temp);
    Q_INVOKABLE bool verifyPassword(QString temp);

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
    Q_INVOKABLE void storeSensorData();
    int counter = 0;

    // charts
    QDateTimeAxis* axisXTimes[chartsNumber];

    //for storing data
    JsonStoring jsonStoring;

    // for sending file
    int counterForSending = 10;
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
    int maxDistance;
    int maxAccelarator;
    Q_INVOKABLE void colibrate(QString name, int maxDis, int maxAcc);
    void addToColibrate(int colibrateValue);
    Q_INVOKABLE void removeColibrateItem(QString temp);
    Q_INVOKABLE QStringList getColibratesNames();
    Q_INVOKABLE void setSelectedColibrate(int temp);
    int calibrate = 1;
    int pdg, pda;

    // filter
    Q_INVOKABLE bool setFilter(double f1, double f2, bool bandPassEnabled);

    // message
    QQueue<QString> messages;
    Q_INVOKABLE QString getMessage();
signals:

public slots:
    void updateChart(QAbstractSeries *chartSeries, int floorNum);

    void setAxisXTime(QDateTimeAxis *axis, int num);
    void selectedFile(QString path);

private:
    SensorsList *mList;
    GroundMotionList *gList;
    ColibrateItemModel *cModel;
private slots:
    void recieveSerialPort();
    void timerSlot();
};

#endif // BACKEND_H
