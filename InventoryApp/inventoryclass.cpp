#include "inventoryclass.h"
#include <QFile>

InventoryClass::InventoryClass(QObject *parent): QObject{parent}
{
    load();
}

void InventoryClass::add(QString name, int Qty)
{
    if(m_items.contains(name))
    {
        m_items[name]+=Qty;
    }else
        m_items.insert(name, Qty);
}

void InventoryClass::remove(QString name, int Qty)
{
    if(m_items.contains(name)){
        m_items[name]-=Qty;
        if(m_items.value(name)<0) m_items.remove(name);
        qInfo()<<"Item removed";
    }else
        qWarning()<<"No! Item found";
}

void InventoryClass::list()
{
    qInfo()<<"Item: "<<m_items.size();
    foreach(QString key, m_items.keys())
    {
        qInfo()<<key<<" : "<<m_items.value(key);

    }
}
#if 0
void InventoryClass::save()
{
    QFile file("A:/QT/InventoryApp/invent.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical()<<"Could not save File: "<<file.errorString();
        return;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_1);
    int len = m_items.size();
    stream<<len;

    qInfo()<<"Number of item to save: "<<len;
    foreach(QString key, m_items.keys())
    {
        qInfo()<<"Saving..."<<key;
        stream<<key;
        stream<<m_items.value(key);
    }
    file.close();
    qInfo()<<"File Saved! ";
}
#endif

void InventoryClass::save()
{
    QFile file("A:/QT/InventoryApp/invent.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qCritical() << "Could not save File: " << file.errorString();
        return;
    }

    QTextStream stream(&file);
    foreach(QString key, m_items.keys()) {
        stream << key << " " << m_items.value(key) << "\n";
    }
    file.close();
    qInfo() << "File Saved!";
}

#if 0
void InventoryClass::load()
{

    QFile file("A:/QT/InventoryApp/invent.txt");
    if(!file.exists()){
        qWarning()<<"File does not exits!";
        return;
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical()<<"File could not open! "<<file.errorString();
        return;
    }
    QDataStream stream(&file);
    // if(stream.version()!= QDataStream::Qt_6_1)
    // {
    //     qCritical()<<"Wrong data stream version!";
    //     file.close();
    //     return;
    // }
    m_items.clear();
    int max;
    stream>>max;
    qInfo()<<"Number of Item to be load! "<<max;
    for(int i=0; i<max; i++)
    {
        QString key;
        int Qty;
        stream>>key;
        stream>>Qty;
        m_items.insert(key, Qty);
    }
    file.close();
    qInfo()<<"File loaded! ";


}
#endif
void InventoryClass::load()
{
    QFile file("A:/QT/InventoryApp/invent.txt");
    if(!file.exists()) {
        qWarning() << "File does not exist!";
        return;
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "File could not open! " << file.errorString();
        return;
    }

    QTextStream stream(&file);
    m_items.clear();
    while (!stream.atEnd()) {
        QString key;
        int Qty;
        stream >> key >> Qty;
        m_items.insert(key, Qty);
    }
    file.close();
    qInfo() << "File loaded!";
}
