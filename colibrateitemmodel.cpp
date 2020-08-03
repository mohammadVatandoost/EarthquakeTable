#include "colibrateitemmodel.h"
#include "colibrateitemlist.h"


ColibrateItemModel::ColibrateItemModel(QObject *parent)
{
    mList = new ColibrateItemList();
}

int ColibrateItemModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    // FIXME: Implement me!
    return mList->items().size();
}

QVariant ColibrateItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    const ColibrateItem item = mList->items().at(index.row());
    switch (role) {
     case Name:
        return QVariant(item.name);
     case colibrate:
        return QVariant(item.colibrate);
    case pda:
       return QVariant(item.maxDis);
    case pga:
       return QVariant(item.maxAccelarator);
    }

    return QVariant();
}

bool ColibrateItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;

    ColibrateItem item = mList->items().at(index.row());
    switch (role) {
     case Name:
        item.name = value.toString();
     case colibrate:
       item.colibrate = value.toInt();
    case pda:
       item.maxDis = value.toInt();
    case pga:
      item.maxAccelarator = value.toInt();
    }

    if(mList->setColibrateItem(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
//    if (data(index, role) != value) {
//        // FIXME: Implement me!
//        emit dataChanged(index, index, QVector<int>() << role);
//        return true;
//    }
    return false;
}

QHash<int, QByteArray> ColibrateItemModel::roleNames() const
{
  QHash<int, QByteArray> names;
  names[Name] = "Name";
  names[colibrate] = "colibrate" ;
  names[pda] = "pda";
  names[pga] = "pga" ;
  return names;
}

Qt::ItemFlags ColibrateItemModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

ColibrateItemList *ColibrateItemModel::list() const
{
    return mList;
}

void ColibrateItemModel::setList(ColibrateItemList *list)
{
    beginResetModel();
    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList) {
        connect(mList, &ColibrateItemList::preItemAppended, this, [this]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &ColibrateItemList::postItemAppended, this, [this]() {
          endInsertRows();
        });
        connect(mList, &ColibrateItemList::preItemRemoved, this, [this](int index) {
          beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &ColibrateItemList::postItemRemoved, this, [this]() {
          endRemoveRows();
        });
        connect(mList, &ColibrateItemList::notifyInfoDataChanged, this, [this]() {
          beginResetModel();
          endResetModel();
        });
//        connect(mList, &SensorsList::notifyInfoDataChanged, this, [this](int index) {
//          dataChanged(index, index, QVector<int>() << role);
//        });
    }

    endResetModel();
}

void ColibrateItemModel::makeNewConfig(QString name, int colibrate, int pda, int pga)
{
    ColibrateItem temp;
    temp.name = name; temp.colibrate = colibrate;
    temp.maxAccelarator = pda; temp.maxDis = pga;
    beginResetModel();
    mList->ColibrateItems.append(temp);
    endResetModel();
}

void ColibrateItemModel::addColibrate(ColibrateItem calibrateItem)
{
    beginResetModel();
    mList->ColibrateItems.append(calibrateItem);
    endResetModel();
}

void ColibrateItemModel::removeItem(QString name)
{
    beginResetModel();
    mList->removeItem(name);
    endResetModel();
}


