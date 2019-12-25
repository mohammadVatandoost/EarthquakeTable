#include "colibrateitemlist.h"

ColibrateItemList::ColibrateItemList(QObject *parent) : QObject(parent)
{

}

bool ColibrateItemList::setColibrateItem(int index, ColibrateItem &gm)
{
    if(index <0 || index >= ColibrateItems.size())
        return false;

    ColibrateItems[index] = gm;
    return true;
}

QVector<ColibrateItem> ColibrateItemList::items()
{
    return ColibrateItems;
}

void ColibrateItemList::appendItem(ColibrateItem temp)
{
    emit preItemAppended();
    ColibrateItems.append(temp);
    emit postItemAppended();
}

void ColibrateItemList::removeItem(int index)
{
    emit preItemRemoved(index);
    ColibrateItems.removeAt(index);
    emit postItemRemoved();
}

