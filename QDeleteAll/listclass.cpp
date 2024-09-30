#include "listclass.h"

ListClass::ListClass(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructor" << parent;
}

ListClass::~ListClass()  // Missing destructor implementation
{
    qInfo() << this << "Destructor";
}
