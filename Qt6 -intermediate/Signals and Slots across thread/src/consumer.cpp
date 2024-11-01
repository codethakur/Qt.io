#include "consumer.h"
#include <QDateTime>  // Add for timestamps

consumer::consumer(QObject *parent) : QObject{parent} {
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
    << "[Consumer Constructed]" << QThread::currentThread();
}

consumer::~consumer() {
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
    << "[Consumer Destructed]" << QThread::currentThread();
}

void consumer::startTimer() {
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
    << "[Consumer timer started]" << "on" << QThread::currentThread();
}

void consumer::consume(int value) {
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
    << "[Consume]" << value << "on" << QThread::currentThread();
}
