#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QDebug>
#include <QList>

class Entity : public QObject
{
    Q_OBJECT
public:
    explicit Entity(QObject *parent = nullptr);

    void DeleteAll(QList<Entity*> &list);
    ~Entity();

signals:
};

#endif // ENTITY_H
