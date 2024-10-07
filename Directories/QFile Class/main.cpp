#include <QCoreApplication>
#include<QFile>
#include<QTextStream>
#include <QDir>
void FileOps()
{
    QFile file("text.txt");


    if(!file.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        qCritical()<<" Could not open!";
        qCritical()<<file.errorString();
    }else{
        qInfo()<<"Writing......";
        file.write(QByteArray("Hello World"));
        file.flush();
    }
    qInfo()<<"Reading......!";
    file.seek(0);
    qInfo()<<file.readAll();
    file.close();
}

bool WriteFile()
{
    QFile file("text.txt");
    if(!file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        qCritical()<<file.errorString();
        return false;
    }
    QTextStream stream(&file);
    for(int i=0; i<5; i++)
    {
        stream<<QString::number(i)<<"¡Hola, Mundo!\n";
    }
    file.close();
    return true;
}

void ReadFile()
{
    QFile file("A:/QT/QFile/text.txt");
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qCritical()<<file.errorString();
        qCritical()<<"File Not Found\n 4041";
    }
    else{
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString line = stream.readLine();
            qInfo()<<line<<"\n";
        }
        file.close();
    }
    QDir dir("c:/QT/QFile");
    qInfo()<<"List directories in the current directory of the file\n";
    QStringList folderList = dir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);


    foreach (QString folder, folderList) {
        qInfo() << folder;
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ReadFile();
    return a.exec();
}
