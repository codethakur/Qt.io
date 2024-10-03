#include "MapClass.h"
#include<QDebug>

MapClass::MapClass(QObject *parent) : QObject(parent), m_id(0), m_name("") {}

MapClass::~MapClass() {}

// Getter for name
QString MapClass::name() const
{
    return m_name;
}

// Setter for name
void MapClass::SetName(const QString &name)
{
    m_name = name;
}

// Getter for id
int MapClass::id() const
{
    return m_id;
}

// Setter for id
void MapClass::SetId(int id)
{
    m_id = id;
}
