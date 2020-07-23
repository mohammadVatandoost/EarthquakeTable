#ifndef COLIBRATEITEMLIST_H
#define COLIBRATEITEMLIST_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include "generaldata.h"

class ColibrateItemList : public QObject
{
    Q_OBJECT
public:
    explicit ColibrateItemList(QObject *parent = nullptr);
    bool setColibrateItem(int index, ColibrateItem &ci);
    QVector<ColibrateItem> items();
    QVector<ColibrateItem> ColibrateItems;
    Q_INVOKABLE void removeItem(QString name);
    Q_INVOKABLE void reRenderModel();
signals:
   void preItemAppended();
   void postItemAppended();

   void preItemRemoved(int index);
   void postItemRemoved();
   void notifyInfoDataChanged();
public slots:
    void appendItem(ColibrateItem temp); //Sensor sensorItem
    void removeItem(int index);
};

#endif // COLIBRATEITEMLIST_H
