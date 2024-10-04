#ifndef QDEBUGCLASS_H
#define QDEBUGCLASS_H

#include <QObject>
#include <QDebug>

class QDebugClass : public QObject
{
    Q_OBJECT
public:
    explicit QDebugClass(QObject *parent = nullptr);
    void Object();

signals:
};

#endif // QDEBUGCLASS_H
