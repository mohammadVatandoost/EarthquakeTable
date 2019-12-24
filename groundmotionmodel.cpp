#include "groundmotionmodel.h"
#include "groundmotionlist.h"

GroundMotionModel::GroundMotionModel()
{

}


int GroundMotionModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    // FIXME: Implement me!
    return mList->items().size();
}

QVariant GroundMotionModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    const GroundMotion item = mList->items().at(index.row());
    switch (role) {
     case name:
        return QVariant(item.name);
     case timeStep:
        return QVariant(item.timeStep);
    case fileDirectory:
       return QVariant(item.fileDirectory);
    }

    return QVariant();
}

bool GroundMotionModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;

    GroundMotion item = mList->items().at(index.row());
    switch (role) {
     case name:
        item.name = value.toString();
     case timeStep:
       item.timeStep = value.toInt();
     case fileDirectory:
       item.fileDirectory = value.toString();
    }

    if(mList->setSensorItem(index.row(), item)) {
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

QHash<int, QByteArray> GroundMotionModel::roleNames() const
{
  QHash<int, QByteArray> names;
  names[tempSetPoint] = "tempSetPoint";
  names[res] = "res" ;
  names[current] = "current" ;
  names[lowPassFilter] = "lowPassFilter" ;
  names[R0] = "R0" ;
  names[Rtol] = "Rtol";
  names[operationTime] = "operationTime" ;
  names[recoveryTemp] = "recoveryTemp" ;
  names[gasType] = "gasType";
  names[pressureType] = "pressureType" ;
  names[equation] = "equation" ;
  names[RtoR0OrRtoDeltaR] = "RtoR0OrRtoDeltaR" ;
  names[tempActive] = "tempActive" ;
  names[heaterActive] = "heaterActive" ;
  names[sensorActive] = "sensorActive" ;
  names[alghoritmRunning] = "alghoritmRunning" ;
  names[pressure] = "pressure" ;
  return names;
}

Qt::ItemFlags GroundMotionModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

SensorsList *GroundMotionModel::list() const
{
    return mList;
}

void GroundMotionModel::setList(SensorsList *list)
{
    beginResetModel();
    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList) {
        connect(mList, &SensorsList::preItemAppended, this, [this]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &SensorsList::postItemAppended, this, [this]() {
          endInsertRows();
        });
        connect(mList, &SensorsList::preItemRemoved, this, [this](int index) {
          beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &SensorsList::postItemRemoved, this, [this]() {
          endRemoveRows();
        });
//        connect(mList, &SensorsList::notifyInfoDataChanged, this, [this](int index) {
//          dataChanged(index, index, QVector<int>() << role);
//        });
    }

    endResetModel();
}


