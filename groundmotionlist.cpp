#include "groundmotionlist.h"

GroundMotionList::GroundMotionList(QObject *parent) : QObject(parent)
{

}

bool GroundMotionList::setGroundMotionItem(int index, GroundMotion &gm)
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
