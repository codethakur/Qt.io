#ifndef LOGGER_H
#define LOGGER_H

#include<QObject>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include<iostream>
#include <QDateTime>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

    static bool logging;           // Controls whether logging is enabled
    static QString fileName;       // File path to log messages
    static void attach();          // Attach the custom message handler
    static void handler(QtMsgType type, const QMessageLogContext &context, const QString &msg); // Custom message handler

signals:

};

#endif // LOGGER_H
