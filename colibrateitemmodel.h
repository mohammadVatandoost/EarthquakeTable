#ifndef COLIBRATEITEMMODEL_H
#define COLIBRATEITEMMODEL_H

#include <QAbstractListModel>
#include "generaldata.h"

class ColibrateItemList;


class ColibrateItemModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ColibrateItemList *list READ list WRITE setList )
public:
    explicit ColibrateItemModel(QObject *parent = nullptr);
    enum {
      Name, colibrate, pda, pga
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
    ColibrateItemList *mList;
    Q_INVOKABLE void makeNewConfig(QString name, int colibrate, int pda, int pga);
    void addColibrate(ColibrateItem calibrateItem);
    void removeItem(QString name);
private:

};

#endif // COLIBRATEITEMMODEL_H
