#ifndef ZIPPROCESS_H
#define ZIPPROCESS_H

#include <QObject>
#include <QProcess>
#include <QRandomGenerator>
#include <QFile>
#include <QDebug>

class ZipProcess : public QObject
{
    Q_OBJECT
public:
    explicit ZipProcess(QObject *parent = nullptr);

    bool ZipCompress();
    bool ZipExtract(const QString &zipFilePath, const QString &outputDir);

    ~ZipProcess();

signals:
};

#endif // ZIPPROCESS_H
