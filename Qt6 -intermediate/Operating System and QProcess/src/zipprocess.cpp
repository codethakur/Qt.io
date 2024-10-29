#include "zipprocess.h"
#include <QTemporaryFile>

ZipProcess::ZipProcess(QObject *parent)
    : QObject{parent}
{}

ZipProcess::~ZipProcess()
{}

bool ZipProcess::ZipCompress()
{
    QByteArray data;
    int max = QRandomGenerator::global()->bounded(1000);
    for (int i = 0; i <= max; i++) {
        QString item = "number:" + QString::number(i) + "\n";
        data.append(item.toUtf8());
    }

    // Write data to a temporary file
    QTemporaryFile tempFile;
    if (!tempFile.open()) {
        qWarning() << "Failed to create temporary file";
        return false;
    }
    tempFile.write(data);
    tempFile.flush();
    tempFile.close();

    // Prepare to read compressed data
    QByteArray result;

    // Compress the temporary file using 7z
    QString zipFileName = "compressed.7z";  // Using .7z extension for 7-Zip
    QProcess zipProcess;

    // Start the 7-Zip process
    zipProcess.start("C:/Program Files/7-Zip/7z.exe", QStringList() << "a" << zipFileName << tempFile.fileName());

    if (!zipProcess.waitForStarted(3000)) {
        qWarning() << "Failed to start 7-Zip process";
        return false;
    }

    if (!zipProcess.waitForFinished(3000)) {
        qWarning() << "7-Zip process failed to finish";
        return false;
    }

    qInfo() << "Original data size:" << data.size();

    // Read the compressed result (7z does not output the compressed data to stdout)
    QFile zipFile(zipFileName);
    if (zipFile.open(QIODevice::ReadOnly)) {
        result = zipFile.readAll();  // If you want to read the compressed file
        qInfo() << "Compressed result size:" << result.size();
        zipFile.close();
    } else {
        qWarning() << "Failed to read compressed file";
        return false;
    }

    QString path("A:/Qt6/SystemInfo/compressed.7z");  // Update the path as needed
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) return false;

    file.write(result);  // Writing the compressed data
    file.close();
    qInfo() << "File saved successfully!";

    return true;
}
bool ZipProcess::ZipExtract(const QString &zipFilePath, const QString &outputDir)
{
    QProcess zipProcess;

    // Start the 7-Zip process for extraction
    zipProcess.start("C:/Program Files/7-Zip/7z.exe", QStringList() << "x" << zipFilePath << "-o" + outputDir);

    if (!zipProcess.waitForStarted(3000)) {
        qWarning() << "Failed to start 7-Zip process for extraction";
        return false;
    }

    if (!zipProcess.waitForFinished(3000)) {
        qWarning() << "7-Zip extraction process failed to finish";
        return false;
    }

    qInfo() << "Extraction completed successfully.";
    return true;
}
