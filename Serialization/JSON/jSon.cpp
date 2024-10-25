#include "jsonconverter.h"
#include "entity.h"
#include <QVariant>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JosonConverter::JosonConverter(QObject *parent)
    : QObject{parent}
{}

void JosonConverter::writeJson(Entity *entityObj, QString path)
{
    QVariantMap v_Map;
    QVariantMap v_itemsMap;

    // Populate v_itemsMap with data from entityObj
    foreach(QString key, entityObj->map().keys()) {
        v_itemsMap.insert(key, QVariant(entityObj->map().value(key)));
    }

    // Add the items map to the main map under the key "Item"
    v_Map["Item"] = QVariant(v_itemsMap);

    // Convert the QVariantMap to a JSON document
    QJsonDocument document = QJsonDocument::fromVariant(v_Map);

    // Open the file in write-only mode
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Could not write to file!";
        qCritical() << file.errorString();
        return;
    }

    // Write the JSON document to the file in a readable format
    file.write(document.toJson(QJsonDocument::Indented));
    file.close();

    qInfo() << "JSON saved successfully to:" << path;
}

Entity* JosonConverter::ReadJsonData(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not open file for reading!";
        qCritical() << file.errorString();
        return nullptr;
    }

    // Read JSON document from file
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);

    if (document.isNull() || !document.isObject()) {
        qCritical() << "Invalid JSON data!";
        return nullptr;
    }
    // Create a new Entity object to populate with data
    Entity *entity = new Entity();

    // Extract JSON object
    QJsonObject jsonObject = document.object();
    QJsonObject itemsObject = jsonObject["Item"].toObject();

    // Populate the Entity object from JSON data
    QMap<QString, QString> map;
    for (QString key : itemsObject.keys()) {
        map.insert(key, itemsObject[key].toString());
    }
    entity->setMap(map);

    return entity;
}
#if 0
Entity* JosonConverter::ReadJsonData(QString path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not open file for reading!";
        return nullptr;
    }

    QByteArray jsonData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    file.close();

    if (document.isNull() || !document.isObject()) {
        qCritical() << "Invalid JSON data!";
        return nullptr;
    }

    QJsonObject jsonObject = document.object();
    QJsonObject itemsObject = jsonObject["Item"].toObject();

    Entity* entity = new Entity();  // Dynamically allocate an Entity object
    // Populate the Entity object from the itemsObject
    foreach (QString key, itemsObject.keys()) {
        QString value = itemsObject[key].toString();
        entity->SetName(key);  // Assuming SetName sets the entity name
        entity->map().insert(key, value);  // Assuming this updates the internal map
    }

    return entity;
}
#endif
