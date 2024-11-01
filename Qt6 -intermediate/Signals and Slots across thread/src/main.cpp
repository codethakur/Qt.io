#include <QCoreApplication>
#include <QDebug>
#include "producer.h"
#include "consumer.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Main Thread:" << QThread::currentThread();

    // Set up the Producer
    QThread pThread;
    pThread.setObjectName("Producer Thread");
    producer *pro = new producer();
    pro->moveToThread(&pThread);

    QObject::connect(&pThread, &QThread::started, pro, &producer::start);
    QObject::connect(&pThread, &QThread::finished, pro, &producer::deleteLater);

    // Set up the Consumer
    QThread cThread;
    cThread.setObjectName("Consumer Thread");
    consumer *con = new consumer();
    con->moveToThread(&cThread);

    QObject::connect(&cThread, &QThread::started, con, &consumer::startTimer);
    QObject::connect(&cThread, &QThread::finished, con, &consumer::deleteLater);

    // Connect the Producer's signal to the Consumer's slot
    QObject::connect(pro, &producer::produce, con, &consumer::consume);

    // Start the threads
    pThread.start();
    cThread.start();

    // Ensure threads are properly cleaned up on exit
    QObject::connect(&a, &QCoreApplication::aboutToQuit, [&]() {
        pThread.quit();
        pThread.wait();
        cThread.quit();
        cThread.wait();
    });

    return a.exec();
}
