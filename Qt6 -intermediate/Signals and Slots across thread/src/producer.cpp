#include "producer.h"
#include <QDateTime>  // Add for timestamps

producer::producer(QObject *parent) : QObject{parent} {
    m_count = 0;
    m_max = 5;
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
            << "[Producer Constructed]" << this << "on" << QThread::currentThread();
}

producer::~producer() {
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
    << "[Producer Destructed]" << this << "on" << QThread::currentThread();
}

void producer::start() {
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
    << "[Producer Starting]" << "on:" << QThread::currentThread();
    m_timer = new QTimer(this);

    connect(m_timer, &QTimer::timeout, this, &producer::timeout);
    connect(this, &producer::finished, m_timer, &QTimer::stop);

    m_timer->setInterval(1000);
    m_timer->start();
}

void producer::timeout() {
    int value = QRandomGenerator::global()->bounded(1000);
    qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
            << "[Produced]" << value << "on" << QThread::currentThread();
    emit produce(value);
    qInfo()<<"\ncount:"<<m_count++;
    if (m_count >= m_max) {
        qInfo() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz")
        << "[Reached max count, finishing production]" << "on" << QThread::currentThread();
        qInfo()<<"\nmax"<<m_max<<"Count: "<<m_count;
        emit finished();
    }
}
