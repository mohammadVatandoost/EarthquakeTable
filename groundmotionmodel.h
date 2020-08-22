#ifndef GROUNDMOTIONMODEL_H
#define GROUNDMOTIONMODEL_H

#include <QAbstractListModel>



class GroundMotionList;


//struct GroundMotion {
//    QString name = "";
//    int timeStep = 10;
//    QString fileDirectory = "";
//};
class GroundMotionModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(GroundMotionList *list READ list WRITE setList )
public:
    GroundMotionModel();
    enum {
      name, timeStep, fileDirectory, fileName
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    virtual QHash<int, QByteArray> roleNames() const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // for sensorList Q_PROPERTY
    GroundMotionList *list() const;
    void setList(GroundMotionList *list);
private:
    GroundMotionList *mList;
};

#endif // GROUNDMOTIONMODEL_H
