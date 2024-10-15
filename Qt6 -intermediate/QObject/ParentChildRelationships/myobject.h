#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr, QString name = "");
    ~MyObject();


signals:
};

#endif // MYOBJECT_H
