#include "logger.h"

// Initialize static members
QString Logger::fileName("A:/Qt6/QLoggingCategory/output/customMessageHandler.txt");
bool Logger::logging = false; // Initially, logging is off

// Save the default Qt message handler
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Logger::Logger(QObject *parent) : QObject(parent) {}

void Logger::attach() {
    // Attach the custom handler (do NOT set Logger::logging to true here)
    qInstallMessageHandler(Logger::handler);
}

void Logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    qDebug() << "Logging state:" << Logger::logging; // Debugging to check logging state

    if (Logger::logging) {
        switch (type) {
        case QtDebugMsg:
            fprintf(stderr, "Debug: %s (%s:%u, %s)\n", msg.toLocal8Bit().constData(), context.file, context.line, context.function);
            break;
        case QtWarningMsg:
            fprintf(stderr, "Warning: %s (%s:%u, %s)\n", msg.toLocal8Bit().constData(), context.file, context.line, context.function);
            break;
        case QtCriticalMsg:
            fprintf(stderr, "Critical: %s (%s:%u, %s)\n", msg.toLocal8Bit().constData(), context.file, context.line, context.function);
            break;
        case QtFatalMsg:
            fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", msg.toLocal8Bit().constData(), context.file, context.line, context.function);
            abort();
        }

        // Open file and append the message
        QFile file(Logger::fileName);
        if (file.open(QIODevice::Append)) {
            QTextStream ts(&file);
            ts << QDateTime::currentDateTime().toString() << ": " << msg
               << " (File: " << context.file << ", Line: " << context.line << ", Function: " << context.function << ")\n";
            file.close();
        }
    }

    // Optionally call the default handler
    if (QT_DEFAULT_MESSAGE_HANDLER) {
        QT_DEFAULT_MESSAGE_HANDLER(type, context, msg);
    }
}
