#include "listclass.h"

ListClass::ListClass(QObject *parent)
    : QObject(parent)
{
    qInfo() << this << "Constructed";
}

ListClass::~ListClass()
{
    qInfo() << this << "Deconstructed";
}
