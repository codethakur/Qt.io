#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QMap>
#include <QDebug>
#include <QDataStream>

class Entity : public QObject
{
    Q_OBJECT
public:
    explicit Entity(QObject *parent = nullptr);
    void fill();
    QString Name();
    void SetName(QString value);
    QMap<QString, QString> map() const;
    void setMap( QMap<QString, QString> newMap);

    // Serialize the entity to the stream (output operator)
    friend QDataStream& operator<<(QDataStream &stream, const Entity &entity)
    {
        qInfo() << "operator<<";
        stream << entity.m_Name;
        stream << entity.m_map;
        return stream;
    }

    // Deserialize the entity from the stream (input operator)
    friend QDataStream& operator>>(QDataStream &stream, Entity &entity)
    {
        qInfo() << "operator>>";
        stream >> entity.m_Name;
        stream >> entity.m_map;
        return stream;
    }


signals:

private:
    QString m_Name;
    QMap<QString, QString> m_map;
};

#endif // ENTITY_H
