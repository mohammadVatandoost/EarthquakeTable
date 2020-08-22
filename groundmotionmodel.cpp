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

//    return 0;
//     qDebug()<< " GroundMotionModel::rowCount ";
//    qDebug()<< " GroundMotionModel::rowCount : "<< mList->groundMotionItems.size();
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
    case fileName:
       return QVariant(item.fileName);
    }

    return QVariant();
}

bool GroundMotionModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;

    // This is very important to prevent items to be garbage collected in JS!!!
//    QDeclarativeEngine::setObjectOwnership(item, QDeclarativeEngine::CppOwnersh

    GroundMotion item = mList->items().at(index.row());
    switch (role) {
     case name:
        item.name = value.toString();
     case timeStep:
       item.timeStep = value.toInt();
     case fileDirectory:
       item.fileDirectory = value.toString();
     case fileName:
       item.fileName = value.toString();
    }

    if(mList->setGroundMotion(index.row(), item)) {
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
  names[name] = "name";
  names[timeStep] = "timeStep" ;
  names[fileDirectory] = "fileDirectory" ;
  names[fileName] = "fileName" ;
  return names;
}

Qt::ItemFlags GroundMotionModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

GroundMotionList *GroundMotionModel::list() const
{
    return mList;
}

void GroundMotionModel::setList(GroundMotionList *list)
{

//    qDebug()<<"********set List";
//    qDebug() << "list->groundMotionItems.size() :" << list->groundMotionItems.size();
    beginResetModel();
//    if(mList) {
//        qDebug() << "list->mList.size() :" << mList->groundMotionItems.size();
//        mList->disconnect(this);
//    }


    mList = list;

    if(mList) {
        connect(mList, &GroundMotionList::preItemAppended, this, [this]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &GroundMotionList::postItemAppended, this, [this]() {
          endInsertRows();
        });
        connect(mList, &GroundMotionList::preItemRemoved, this, [this](int index) {
          beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &GroundMotionList::postItemRemoved, this, [this]() {
          endRemoveRows();
        });
        connect(mList, &GroundMotionList::notifyInfoDataChanged, this, [this]() {
          beginResetModel();
          endResetModel();
        });
//        connect(mList, &SensorsList::notifyInfoDataChanged, this, [this](int index) {
//          dataChanged(index, index, QVector<int>() << role);
//        });
    }

    endResetModel();
}


