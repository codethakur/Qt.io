#include "entity.h"

Entity::Entity(QObject *parent)
    : QObject{parent}
{}

void Entity::fill()
{
    m_Name = "EntityObject";
    for (int i = 0; i < 10; i++)
    {
        QString Num = QString::number(i);
        QString key = "Key " + Num;

        if (i % 2 != 0)
        {
            QString value = "This is odd Num: " + Num;
            m_map.insert(key, value);
        }
    }
}

QString Entity::Name()
{
    return m_Name;
}

void Entity::SetName(QString value)
{
    m_Name = value;
}

QMap<QString, QString> Entity::map() const
{
    return m_map;
}

void Entity::setMap(QMap<QString, QString> newMap)
{
    m_map = newMap;
}
