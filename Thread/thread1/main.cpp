#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "work.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Starting...\n" << QThread::currentThread()->objectName();

    work *Work = new work();
    QThread thread;

    thread.setObjectName("Worker Thread");
    Work->moveToThread(&thread);

    QObject::connect(&thread, &QThread::started, Work, &work::run);

    thread.start();

    qInfo() << "Working...";
    for (int i = 1; i <= 10; i++) // Start from 1
    {
        qInfo() << "Dev...\n" << QString::number(i) << "name =" << QThread::currentThread()->objectName();
        QThread::currentThread()->msleep(500);
    }

    qInfo() << "Finished!" << "name =" << QThread::currentThread()->objectName();

    return a.exec();
}
