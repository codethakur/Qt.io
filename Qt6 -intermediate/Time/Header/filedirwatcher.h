#ifndef FILEDIRWATCHER_H
#define FILEDIRWATCHER_H

#include <QObject>
#include<QDir>
#include<QDebug>
#include<QFileSystemWatcher>
#include<QFile>

class FileDirWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileDirWatcher(QObject *parent = nullptr);

signals:
public slots:
    void directoryChanged(const QString &path);
    void fileChanged(const QString &path);

private:
    QFileSystemWatcher fsw;
};

#endif // FILEDIRWATCHER_H
