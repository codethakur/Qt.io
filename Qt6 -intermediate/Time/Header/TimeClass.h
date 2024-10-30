#ifndef TIMECLASS_H
#define TIMECLASS_H

#include <QObject>
#include<QDebug>
#include<QTimer>
#include<QTime>


class TimeClass : public QObject
{
    Q_OBJECT
public:
    explicit TimeClass(QObject *parent = nullptr);

signals:
public slots:
    void timeout();
    void timestart();
private:
    QTimer timer;
    int number;
};

#endif // TIMECLASS_H
