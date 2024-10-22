#include <QCoreApplication>
#include <QDebug>
#include "logger.h"
#include "test.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qInfo() << "File: " << Logger::fileName;

    // Attach the logger handler (but logging is initially off)
    Logger::attach();

    qInfo() << "---------------------------------\n";

    // Set logging to false, the following message will not be logged
    Logger::logging = false;
    qInfo() << "This will not be logged\n";  // This message won't appear in the file

    // Enable logging
    Logger::logging = true;
    qInfo() << "This will be logged\n";  // This message will appear in the file

    // Test class example
    Test test;
    test.testing();  // Call your test function which should also log something

    return a.exec();
}
