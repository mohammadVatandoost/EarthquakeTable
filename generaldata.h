#ifndef GENERALDATA_H
#define GENERALDATA_H
#include <iostream>
#include <QString>
#include <QVector>
#include <vector>

#define offValue  100

using namespace std;

struct GroundMotion {
    QString name = "";
    int timeStep = 10;
    QString fileDirectory = "";
    QString fileName = "";
};

struct ColibrateItem {
    QString name = "";
    int colibrate = 1;
    int maxDis = 14;
    int maxAccelarator = 5;
};

struct GeneralData {
    int torque;
    int floor[4] = {offValue, offValue, offValue, offValue};
    QVector<GroundMotion> groundMotion;
    QVector<ColibrateItem> colibrateItems;
    QString password = "1234";
};


#endif // GENERALDATA_H
