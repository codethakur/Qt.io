#ifndef INVENTORYCLASS_H
#define INVENTORYCLASS_H

#include<QObject>
#include<QMap>
#include<QDebug>
#include<QDataStream>

class InventoryClass : public QObject
{
    Q_OBJECT
public:
    explicit InventoryClass(QObject *parent = nullptr);
    void add(QString name, int Qty);
    void remove(QString name, int Qty);
    void list();

signals:
public slots:
    void save();
    void load();

private:
    QMap<QString,int>m_items;

};

#endif // INVENTORYCLASS_H
