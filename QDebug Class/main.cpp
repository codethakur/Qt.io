#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "qdebugclass.h"

void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    uint line = context.line; // Get the line number

    // Format the message similar to fprintf
    QString formattedMessage;

    switch (type) {
    case QtDebugMsg:
        formattedMessage = QString("Debug: %1 (%2:%3 %4)").arg(localMsg.constData(), file, QString::number(line), function);
        qDebug() << formattedMessage;
        break;
    case QtWarningMsg:
        formattedMessage = QString("Warning: %1 (%2:%3 %4)").arg(localMsg.constData(), file, QString::number(line), function);
        qWarning() << formattedMessage;
        break;
    case QtCriticalMsg:
        formattedMessage = QString("Critical: %1 (%2:%3 %4)").arg(localMsg.constData(), file, QString::number(line), function);
        qCritical() << formattedMessage;
        break;
    case QtFatalMsg:
        formattedMessage = QString("Fatal: %1 (%2:%3 %4)").arg(localMsg.constData(), file, QString::number(line), function);
        qFatal("%s", formattedMessage.toLocal8Bit().constData());
    }
}


void test() {
    qDebug() << "Test:";
    qInfo() << "Test:";
    qWarning() << "Test:";
    qCritical() << "Test:";
    // qFatal("fatal message");

    QDebugClass obj;
    obj.Object();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTextStream qin(stdin);
    bool running = true;

    do {
        std::cout << "Enter a command 'START', 'STOP', 'TEST', or 'EXIT': " << std::endl;
        QString command = qin.readLine();

        qInfo() << "You entered:" << command;

        // Install custom message handler
        if (command.toUpper() == "START") {
            qInstallMessageHandler(myMessageHandler);
            qInfo() << "Message handler installed.";
        }
        // Uninstall custom message handler
        else if (command.toUpper() == "STOP") {
            qInstallMessageHandler(nullptr);
            qInfo() << "Message handler uninstalled.";
        }
        // Execute test function
        else if (command.toUpper() == "TEST") {
            test();
        }
        // Exit the loop
        else if (command.toUpper() == "EXIT") {
            running = false;
            qInfo() << "Exiting...";
        }
        else {
            qWarning() << "Unknown command!";
        }

    } while (running);

    return a.exec();
}
