#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <QObject>
#include<QDebug>
#include<QFile>
#include<QDir>
#include<QVariant>
#include<QVariantMap>
#include<QJsonObject>
#include<QJsonArray>
#include<QMap>
#include<QJsonDocument>
#include"entity.h"


class JosonConverter : public QObject
{
    Q_OBJECT
public:
    explicit JosonConverter(QObject *parent = nullptr);
    static void writeJson(Entity *entity,   QString path );
    static Entity *ReadJsonData(QString path);


signals:
};

#endif // JSONCONVERTER_H
