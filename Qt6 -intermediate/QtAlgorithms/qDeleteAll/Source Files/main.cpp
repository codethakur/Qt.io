#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include<QSharedPointer>
#include<QRandomGenerator>
#include<QMap>
#include "entity.h"

QList<int> makeList()
{
    QList<int> list;
    for (int i = 0; i < 10; i++)
    {
        if(i%2!=0)
            list.append(i);
    }
    return list;
}
void find(const QList<int>& list, int value)
{
    //  int index = list.indexOf(value);
    bool found = false;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == value)
        {
            qInfo() << "Value found at" << i;
            found = true;
            break;
        }
    }

    if (!found)
    {
        qInfo() <<value<<" Not Found";
    }
}


void DeleObjListPtr()
{
    QList<Entity*>list;
    for(int i=0; i<5; i++)
    {
        list.append(new Entity(nullptr, "Item" + QString::number(i)));
    }
    qInfo()<<"-------------------------------------------------\n";
    foreach (Entity* Eptr, list) {
        qInfo()<<Eptr;
    }
    qInfo()<<"-------------------------------------------------\n";

    qDeleteAll(list);
    qInfo()<<"-------------------------------------------------\n";
    qInfo()<<"List Size: "<<list.size();
    qInfo()<<"-------------------------------------------------\n";
    list.clear();
    qInfo()<<"List Size after clear: "<<list.size()<<"List count: "<<list.count();



}

void DeleObjLisSptr()
{
    QList<QSharedPointer<Entity>>Slist;

    for(int i=5; i<=10; i++)
    {
        QSharedPointer<Entity> item(new Entity(nullptr, "Item" +QString::number(i)));
        Slist.append(item);
    }
    qInfo()<<"-------------------------------------------------\n";

    foreach (QSharedPointer<Entity> Sptr, Slist) {
        qInfo()<<Sptr.data();
    }
    qInfo()<<"slit size: "<<Slist.size();
    qInfo()<<"-------------------------------------------------\n";

    Slist.clear();
    qInfo()<<"Slist Size after clear: "<<Slist.size();


}

QVector<QString> nameList = {"Rohit", "Curran", "Shyam", "Hary", "Adaline"};

void DeleObjMapPtr()
{
    QMap<int, Entity*> map;
    for (int i = 0; i < nameList.size(); i++)
    {
        int id = QRandomGenerator::global()->bounded(1000);
        QString name = nameList[i];

        map.insert(id, new Entity(nullptr, name));
    }
    qInfo()<<"--------------------------------------\n";
    foreach (auto key, map.keys())
    {
        qInfo() << key << map[key];
    }
    qDeleteAll(map);
    qInfo()<<"Map  size after delet All:"<<map.size();
    map.clear();
    qInfo()<<"Map  size after delet clear:"<<map.size();
}

typedef QMap<int, QSharedPointer<Entity>>S_map;

void DeleObjMapSptr()
{
    S_map NameMap;

    for (int i = 0; i < nameList.size(); i++)
    {
        int id = QRandomGenerator::global()->bounded(1000);
        QString name = nameList[i];
        QSharedPointer<Entity>Sptr(new Entity(nullptr, name));

        NameMap.insert(id, Sptr);
    }
    qInfo()<<"--------------------------------------\n";
    foreach (auto key, NameMap.keys())
    {
        qInfo() << key << NameMap[key];
    }
    qInfo()<<"NameMap size: "<<NameMap.size();
    NameMap.clear();
    qInfo()<<NameMap.isEmpty();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int>list = makeList();
    qInfo()<<list;
    find(list, 10);

    return a.exec();
}
