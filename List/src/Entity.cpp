#include "entity.h"

Entity::Entity(QObject *parent) :
    QObject{parent}
{
    qInfo() << "Constructed\n" << this;
}

void Entity::DeleteAll(QList<Entity*> &list)  // Define with reference
{
    for (int i = 0; i < 10; i++)
    {
        Entity *entity = new Entity();
        entity->setObjectName(QString::number(i));
        list.append(entity);
    }
    qInfo() << list;

    qInfo() << "\n-------------------------------\n";
    qDeleteAll(list);
    qInfo() << "-------------------------------\n";
    qInfo() << "Count: " << list.count();

    list.clear();

    qInfo() << "\n-------------------------------\n";
    qInfo() << "Count after clearing: " << list.count();
}

Entity::~Entity()
{
    qInfo() << "Destroyed object\n" << this;
}
