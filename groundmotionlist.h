#ifndef GROUNDMOTIONLIST_H
#define GROUNDMOTIONLIST_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include "generaldata.h"

class GroundMotionList : public QObject
{
    Q_OBJECT
public:
    explicit GroundMotionList(QObject *parent = nullptr);
    bool setGroundMotion(int index, GroundMotion &gm);
    QVector<GroundMotion> items();
    QVector<GroundMotion> groundMotionItems;
    Q_INVOKABLE void removeItem(QString name);
    Q_INVOKABLE void reRenderModel();
signals:
   void preItemAppended();
   void postItemAppended();

   void preItemRemoved(int index);
   void postItemRemoved();
   void notifyInfoDataChanged();
public slots:
    void appendItem(GroundMotion temp); //Sensor sensorItem
    void removeItem(int index);
};

#endif // GROUNDMOTIONLIST_H
