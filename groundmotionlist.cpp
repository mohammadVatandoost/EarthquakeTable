#include "groundmotionlist.h"

GroundMotionList::GroundMotionList(QObject *parent) : QObject(parent)
{

}

QVector<GroundMotion> GroundMotionList::items()
{
    return groundMotionItems;
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
