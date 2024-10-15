#include "entity.h"
#include<QDebug>


Entity::Entity(QObject *parent, QString name):QObject(parent)
{
    setObjectName(name);
    qInfo()<< "object is created:\n";
}

Entity::~Entity()
{
    qInfo()<< "object is no longer:\n" ;
}
