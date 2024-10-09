#include "developer.h"

Developer::Developer(QObject *parent) : QObject(parent), m_producer(false), m_count(0) {}

bool Developer::isProducer() const
{
    return m_producer;
}

void Developer::setProducer(bool newProducer)
{
    m_producer = newProducer;
}

void Developer::consume(int value)
{
    qInfo() << this << "Consuming.." << QThread::currentThread()->objectName() << "Value:" << value;
}


void Developer::start()
{
    qInfo() << this << "Starting.." << QThread::currentThread();
    m_timer = new QTimer(this);

    connect(m_timer, &QTimer::timeout, this, &Developer::onTimeout);
    if (m_producer)
    {
        qInfo() << "Starting Timer.." << QThread::currentThread()->objectName();
        m_timer->setInterval(1000);
        m_timer->start();
    }
}

void Developer::quit()
{
    qInfo() << this << "Quitting.." << QThread::currentThread();
    if (m_timer)
    {
        m_timer->stop();
    }
    emit finished();
}


void Developer::onTimeout()
{
    int value = QRandomGenerator::global()->bounded(1000);
    qInfo() << this << "Producing..." << QThread::currentThread()->objectName() << "Value:" << value;
    emit produced(value);
    m_count++;
    if (m_count == 5)
        quit();
}

