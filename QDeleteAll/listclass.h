#ifndef LISTCLASS_H
#define LISTCLASS_H

#include <QObject>
#include<QDebug>

class ListClass :public QObject
{
    Q_OBJECT
public:
    explicit ListClass(QObject *parent = nullptr);
    ~ListClass();
};

#endif // LISTCLASS_H
