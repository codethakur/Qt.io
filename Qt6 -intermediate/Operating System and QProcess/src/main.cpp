#include <QCoreApplication>
#include <QDir>
#include <QProcess>
#include <QDebug>
#include "zipprocess.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ZipProcess zipProcessor;

    // Compressing files
    if (zipProcessor.ZipCompress()) {
        qInfo() << "Compression completed successfully.";
    } else {
        qInfo() << "Compression failed.";
        return 1;  // Exit if compression fails
    }

    // Setting up extraction parameters
    QString zipFilePath = "compressed.7z";  // Path to your 7z file
    QString outputDir = "A:/Qt6/SystemInfo/extracted";  // Desired extraction directory

    // Ensure the output directory exists
    QDir dir;
    if (!dir.exists(outputDir)) {
        if (!dir.mkpath(outputDir)) {
            qWarning() << "Failed to create output directory:" << outputDir;
            return 1;  // Exit if output directory cannot be created
        }
    }

    // Extracting files
    if (zipProcessor.ZipExtract(zipFilePath, outputDir)) {
        qInfo() << "Files extracted successfully to:" << outputDir;

        // Add your process execution here
        QProcess process;
        process.start("cmd", QStringList() << "/C" << "start" << "https://github.com/codethakur");
        process.waitForFinished();  // Wait for the process to finish

        // Check if the process started successfully
        if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0) {
            qInfo() << "Process executed successfully.";
            // You can add any further logic or commands here if needed
            return 0;  // Return success
        } else {
            qWarning() << "Failed to execute the process. Application will close.";
            return 1;  // Exit with failure
        }
    } else {
        qWarning() << "Extraction failed!";
        return 1;  // Exit if extraction fails
    }

    return a.exec();
}
