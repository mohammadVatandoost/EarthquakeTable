#include "colibrateitemlist.h"

ColibrateItemList::ColibrateItemList(QObject *parent) : QObject(parent)
{
//   ColibrateItem temp;
//   temp.name = "test1";
//   temp.colibrate = 100 ;
//   ColibrateItems.append(temp);
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

void ColibrateItemList::removeItem(QString name)
{
    for(int i=0; i<ColibrateItems.size(); i++) {
        if(ColibrateItems[i].name == name) {
            ColibrateItems.remove(i);
            emit notifyInfoDataChanged();
            return;
        }
    }
    qDebug() << "remove item does not find:"<<name ;
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

