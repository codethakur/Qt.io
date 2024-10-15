#include "myobject.h"
#include<QDebug>

MyObject::MyObject(QObject *parent, QString name):QObject(parent)
{
    setObjectName(name);
    qDebug()<<this << "Object created:" << objectName();

}

MyObject::~MyObject()
{
    qDebug()<<this << "Object destroyed:" << objectName();
}
