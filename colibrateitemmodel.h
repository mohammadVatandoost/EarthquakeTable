#ifndef COLIBRATEITEMMODEL_H
#define COLIBRATEITEMMODEL_H

#include <QAbstractListModel>

class ColibrateItemList;


class ColibrateItemModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ColibrateItemList *list READ list WRITE setList )
public:
    ColibrateItemModel();
    enum {
      name, colibrate
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    virtual QHash<int, QByteArray> roleNames() const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // for sensorList Q_PROPERTY
    ColibrateItemList *list() const;
    void setList(ColibrateItemList *list);
private:
    ColibrateItemList *mList;
};

#endif // COLIBRATEITEMMODEL_H
