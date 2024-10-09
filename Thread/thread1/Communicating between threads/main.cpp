#include <QCoreApplication>
#include <QThread>
#include "developer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Developer producer;
    Developer consumer;

    QThread pThread;
    QThread cThread;

    producer.moveToThread(&pThread);
    consumer.moveToThread(&cThread);

    producer.setProducer(true);

    pThread.setObjectName("Producer Thread");
    cThread.setObjectName("Consumer Thread");

    producer.setObjectName("Producer");
    consumer.setObjectName("Consumer");

    QObject::connect(&pThread, &QThread::started, &producer, &Developer::start);
    QObject::connect(&cThread, &QThread::started, &consumer, &Developer::start);

    QObject::connect(&producer, &Developer::produced, &consumer, &Developer::consume);
    QObject::connect(&producer, &Developer::finished, &consumer, &Developer::quit);

    cThread.start();
    pThread.start();

    return a.exec();
}
