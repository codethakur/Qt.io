#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

QtMessageHandler defaultHandler = nullptr;

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    // Custom handling of messages
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

    // Open file and append message
    QFile file("A:/Qt6/QLoggingCategory/customMessageHandler.txt");
    if (file.open(QIODevice::Append)) {
        QTextStream ts(&file);
        ts << QDateTime::currentDateTime().toString() << ": " << msg
           << " (File: " << context.file << ", Line: " << context.line << ", Function: " << context.function << ")\n";
        file.close();
    }

    // Optionally call the default handler
    if (defaultHandler)
        defaultHandler(type, context, msg);
}

int main(int argc, char *argv[]) {
    // Install custom handler and save the default one
    defaultHandler = qInstallMessageHandler(customMessageHandler);

    // Generate some test messages
    qDebug() << "This is a debug message.";
    qWarning() << "This is a warning message.";

    // Restore the default handler
    qInstallMessageHandler(defaultHandler);
    qDebug() << "Back to default handling.";

    return 0;
}
