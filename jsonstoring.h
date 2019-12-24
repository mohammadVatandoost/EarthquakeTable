#ifndef JSONSTORING_H
#define JSONSTORING_H

#include <iostream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include "generaldata.h"
#include "packet.h"

#define GeneralDataFile "GenralData.txt"




using namespace std;

class JsonStoring
{
public:
    JsonStoring();
    void storeGeneralData(GeneralData generalData);
    GeneralData getGeneralData();
    QString jsonToString(QJsonObject jsonObject);
    void storeToFile(QString data, QString fileName);
    QString getFileString(QString fileName);
};

#endif // JSONSTORING_H
