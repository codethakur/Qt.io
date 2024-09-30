#include "ptrclsss.h"
#include <QDebug> // Add this to use qInfo()

ptrClsss::ptrClsss(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructor" << parent;
}

ptrClsss::~ptrClsss()
{
    qInfo() << this << "Deconstructor" << parent();
}

void ptrClsss::message(QString value)
{
    qInfo() << this << value;
}
