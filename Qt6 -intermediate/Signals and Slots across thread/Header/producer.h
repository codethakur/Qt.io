#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include<QTimer>
#include<QRandomGenerator>
#include<QThread>
#include<QDebug>

class producer : public QObject
{
    Q_OBJECT
public:
    explicit producer(QObject *parent = nullptr);
    ~producer();

signals:
    void produce(int value);
    void finished();
public slots:
    void start();
private slots:
    void timeout();
private:
    QTimer *m_timer;
    int m_count;
    int m_max;



};

#endif // PRODUCER_H
