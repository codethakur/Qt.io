#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>

class Entity : public QObject
{
    Q_OBJECT
public:
    explicit Entity(QObject *parent = nullptr, QString name = "");
    ~Entity();

signals:
};

#endif // ENTITY_H