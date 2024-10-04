#include "qdebugclass.h"

QDebugClass::QDebugClass(QObject *parent) : QObject(parent)
{
}

void QDebugClass::Object()
{
    qWarning() << "Hello from QDebug Class!";
}
