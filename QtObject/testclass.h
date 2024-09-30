#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include<QDebug>

class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);

signals:
    void close();
public slots:
    void log();
};

#endif // TESTCLASS_H
