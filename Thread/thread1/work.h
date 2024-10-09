#ifndef WORK_H
#define WORK_H

#include <QObject>
#include<QThread>
#include<QDebug>

class work : public QObject
{
    Q_OBJECT
public:
    explicit work(QObject *parent = nullptr);
    ~work();
signals:
public slots:
    void run();
};

#endif // WORK_H
