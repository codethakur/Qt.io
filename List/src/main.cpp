#include <QCoreApplication>
#include "entity.h"
#include <QList>
#include <QRandomGenerator>

QList<int> RandomGen()
{
    QList<int> list;
    for (int i = 0; i < 10; i++)
    {
        int value = QRandomGenerator::global()->bounded(1000);
        list.append(value);
    }
    return list;  // Return the populated list
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if 0
    Entity *entity = new Entity();
    QList<Entity*> list;
    entity->DeleteAll(list);

    delete entity;

#endif

    QList<int>list;
    list<<1<<2<<3;
    qInfo()<<list;

    list.fill(12);
    qInfo()<<list;

    list.resize(12);
    std::fill(list.begin(), list.end(), 12);
    qInfo()<<list;

    QList<int>list2;
    qInfo()<<"\n-----------------------\n";

    QList<int> data = RandomGen();
    qInfo() <<"Unsorted data: "<< data;

    std::sort(data.begin(), data.end());
    qInfo() <<"Sorted data: "<< data;

    std::reverse(data.begin(), data.end());
     qInfo() <<"reverse data: "<< data;


    return a.exec();
}
