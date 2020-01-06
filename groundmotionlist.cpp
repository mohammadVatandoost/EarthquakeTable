#include "groundmotionlist.h"

GroundMotionList::GroundMotionList(QObject *parent) : QObject(parent)
{
//    GroundMotion temp;
//    temp.name = "test1";
//    temp.timeStep = 10;
//    groundMotionItems.append(temp);
}

bool GroundMotionList::setGroundMotion(int index, GroundMotion &gm)
{
    if(index <0 || index >= groundMotionItems.size())
        return false;

    groundMotionItems[index] = gm;
    return true;
}

QVector<GroundMotion> GroundMotionList::items()
{
    return groundMotionItems;
}

void GroundMotionList::removeItem(QString name)
{
    for(int i=0; i<groundMotionItems.size(); i++) {
        if(groundMotionItems[i].name == name) {
            groundMotionItems.remove(i);
            emit notifyInfoDataChanged();
            return;
        }
    }
    qDebug() << "remove item does not find:"<<name ;
}

void GroundMotionList::appendItem(GroundMotion temp)
{
    emit preItemAppended();
    groundMotionItems.append(temp);
    emit postItemAppended();
}

void GroundMotionList::removeItem(int index)
{
    emit preItemRemoved(index);
    groundMotionItems.removeAt(index);
    emit postItemRemoved();
}
