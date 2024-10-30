#include "filedirwatcher.h"

FileDirWatcher::FileDirWatcher(QObject *parent): QObject{parent}
{
    // fsw.addPath(QDir::currentPath());
    // fsw.addPath(QDir::currentPath() + QDir::separator() + "test.txt");

    QString dirPath = "A:/Qt6/Time"; // Replace with the absolute directory path you want to monitor
    QString filePath = "A:/Qt6/Time/test.txt"; // Absolute path to the file you want to monitor

    fsw.addPath(dirPath);   // Watch directory
    fsw.addPath(filePath);  // Watch file

    qInfo() << "\nWatching directory:" << fsw.directories();

    qInfo()<<"------------------------";
    qInfo() << "\nWatching file:" << fsw.files();
    qInfo()<<"------------------------";

    connect(&fsw, &QFileSystemWatcher::fileChanged, this, &FileDirWatcher::fileChanged);
    connect(&fsw, &QFileSystemWatcher::directoryChanged, this, &FileDirWatcher::directoryChanged);

}

void FileDirWatcher::fileChanged(const QString &path)
{
    qInfo()<<"file changed!";
    if(fsw.files().length())
    {
        qInfo()<<"File that have changed\n";
        foreach(QString file, fsw.files())
        {
            qInfo()<<file;
        }
    }

}

// void FileDirWatcher::directoryChanged(const QString &path)
// {
//     qInfo() << "\ndirectory changed at path:" << path;
//     qInfo()<<"------------------------";

//     // Optionally, list all files in the directory
//     QDir dir(path);
//     foreach (QString file, dir.entryList(QDir::Files))
//     {
//         qInfo() << "\nFile in directory:" << file;
//     }
// }


void FileDirWatcher::directoryChanged(const QString &path)
{
    qInfo()<<"Dir changed!";
    if(fsw.directories().length())
    {
        qInfo()<<"File that have changed\n";
        foreach(QString dir, fsw.directories())
        {
            qInfo()<<dir;
        }
    }

}
