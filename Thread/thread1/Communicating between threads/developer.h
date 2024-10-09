#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QRandomGenerator>

class Developer : public QObject
{
    Q_OBJECT
public:
    explicit Developer(QObject *parent = nullptr);

    bool isProducer() const;
    void setProducer(bool newProducer);

signals:
    void produced(int value);
    void finished();

public slots:
    void consume(int value);
    void start();
    void quit();

private:
    QTimer *m_timer;
    bool m_producer;
    int m_count;
    void onTimeout();
};

#endif // DEVELOPER_H
