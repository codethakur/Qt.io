#include "entity.h"
#include<QDebug>

Entity::Entity(QObject *parent, QString name):QObject(parent)
{
    setObjectName(name);
    qInfo()<<this<<"Constructored";

}

Entity::~Entity()
{
    qInfo()<<this<<"Destroyed ";
}
