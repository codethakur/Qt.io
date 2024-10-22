#include <QCoreApplication>
#include<QIODevice>
#include<QBuffer>
#include<QDebug>
#include<QFile>
#include<QDateTime>
#include<QDir>
#include <QTemporaryFile>
#include <QTextStream>
#include <QDebug>

void ReadWrite()
{
    QBuffer buffer;
    if(buffer.open(QIODevice::ReadWrite))
    {
        qInfo()<<"Device is open!";
        QByteArray data("Hello World");
        for(int i=0; i<5;i++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }


        buffer.seek(0);
        qInfo()<<buffer.readAll();
        qInfo()<<"Close..";
        buffer.close();
    }
    else{
        qInfo()<<buffer.errorString();

    }
    qInfo()<<"Finished!";
}

void WriteOnly()
{
    // Specify the full path to the desired location
    QString fileName = "A:/Qt6/FilesSys/text.txt"; // Desired file path
    QFile file(fileName);

    // Print the current working directory (optional)
    qInfo() << "Current working directory:" << QDir::currentPath();

    if (file.open(QIODevice::WriteOnly))
    {
        qInfo() << "File open!!";

        QString now = QDateTime::currentDateTime().toString();
        QByteArray data;
        data.append(now.toLocal8Bit());
        data.append(" - ");
        data.append("Hello World!!");
        file.write(data);

        file.close();
        qInfo() << "Done!";
    }
    else
    {
        qInfo() << "Could not open the file!";
    }
}


void AppendOnly(QFile &file)
{

    if (file.open(QIODevice::Append))
    {
        qInfo() << "Appended.\n";

        QString now = QDateTime::currentDateTime().toString();
        QByteArray data;
        data.append(now.toLocal8Bit());
        data.append(" - ");
        data.append("Hello World!!");
        file.write(data);

        file.close();
        qInfo() << "Done!\n";
    }
    else
    {
        qInfo() << "Could not open the file!";
    }
}


void readLine(QFile &file)
{
    // Try opening the file in ReadOnly mode
    if (!file.open(QIODevice::ReadOnly)) {
        qInfo() << "Could not open the file for reading!";
        return;
    }

    // Ensure the file is opened in ReadOnly mode
    if (!file.isReadable()) {
        qInfo() << "Could not open the file for reading!";
        return;
    }

    file.seek(0);
    while (!file.atEnd())
    {
        qInfo() << "----" << file.readLine()<<"\n";
    }

    file.close();
}


void ListFile(QDir &root)
{
    qInfo() << "-------------File Listing-----------\n";

    // Iterate through all entries except . and ..
    foreach (QFileInfo fi, root.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot, QDir::Name))
    {
        if (fi.isDir()) {
            qInfo() << "It is Dir:\n" << fi.filePath();

            QDir child(fi.filePath());
            qInfo() << "Inspecting directory:" << fi.absoluteFilePath();
            ListFile(child);
        }
        else if (fi.isFile()) {
            qInfo() << "It is File:\n" << fi.filePath();
        }
    }
}

void saveToTemporaryFile()
{
    tempFile.setFileTemplate(QDir::tempPath()+"tempxxxxxxx.txt");
    tempFile.setAutoRemove(false); // This will prevent the file from being deleted

    if(tempFile.open())
    {
        qDebug()<<"Temporary File is Created!"<<tempFile.fileName();

        QTextStream out(&tempFile);
        out<<"This is temporary data.\n";
        out<<"File will automaticaly delete after closeing\n";

        tempFile.close();
        qDebug() << "Temporary file saved and closed.";
    }else{
        qDebug() << "Failed to create the temporary file.";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Start with the application's directory and move one level up
    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp(); // Move one level up from the application's directory

    // Call the function to list files and directories
    saveToTemporaryFile();

    return a.exec();
}
