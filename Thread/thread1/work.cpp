#include "work.h"

work::work(QObject *parent):QObject(parent)
{
    qInfo() <<this<< "work Constructor" << QThread::currentThread()->objectName();
}

work::~work()
{   qInfo()<<this << "work Constructor" << QThread::currentThread()->objectName();

}

void work::run()
{
    for(int i=0; i<10;i++)
    {
        qInfo()<<"Development.."<<QString::number(i)<<QThread::currentThread();
        QThread::currentThread()->msleep(500);
    }
    this->deleteLater();
}
