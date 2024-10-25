#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDataStream>
#include <QDebug>
#include<QDir>
#include "entity.h"
#include"jsonconverter.h"


bool Save(QString path)
{
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_0);

    QString title = "Serialization!";
    qint64 num= 94;

    out << title;
    out << num;

    file.close();

    return true;
}

bool Read(QString path)
{
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_6_0)
    {
        qCritical() << "Version did not match!";
        file.close();
        return false;
    }

    QString title;
    qint64 num;

    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    file.close();

    return true;
}


bool SaveFile(Entity *entptr, QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) return false;

    QDataStream data(&file);
    data.setVersion(QDataStream::Qt_6_0);

    data << *entptr;  // Serialize the Entity object

    file.close();
    return true;
}

bool LoadFile(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return false;

    QDataStream data(&file);
    data.setVersion(QDataStream::Qt_6_0);  // Ensure the version is correct

    Entity entity;

    // Deserialize the Entity object from the file
    data >> entity;

    file.close();

    // Output the entity's name and its map contents
    qInfo() << "Name:" << entity.Name();
    foreach (QString key, entity.map().keys())
    {
        qInfo() << key << " : " << entity.map().value(key);
    }

    return true;
}

void WriteData(QString path)
{
    Entity data;
    data.fill();

    JosonConverter::writeJson(&data,path);
}

void ReadData(QString path)
{
    Entity *data;
    data=JosonConverter::ReadJsonData(path);

    if(!data){
        qCritical() << "Invalid JSON data!";
        return;
    }
    foreach(QString key, data->map().keys()){
        qInfo()<<key<<": "<<data->map().value(key);
    }

}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QString file("A:/Qt6/Serialization/jsonData.json");

    // Check if the file already exists
    QFileInfo fileInfo(file);
    if (fileInfo.exists()) {
        // File exists, ask user whether to append or overwrite
        qInfo() << "File already exists. Do you want to append (A) or overwrite (O)?";

        QTextStream input(stdin);
        QString choice = input.readLine();

        if (choice.toUpper() == "A") {
            // Append new data to the existing file
            WriteData(file);
            qInfo() << "Data appended successfully to:" << file;
        } else {
            // Overwrite the existing file
            WriteData(file);
            qInfo() << "File overwritten successfully to:" << file;
        }
    } else {
        // File does not exist, create a new file
        WriteData(file);
    }

    // Read the data to display
    ReadData(file);

    return a.exec();
}
