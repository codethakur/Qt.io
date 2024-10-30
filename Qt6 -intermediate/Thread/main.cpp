#include <QCoreApplication>
#include <QThread>
#include <QRandomGenerator>
#include <QTimer>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set the current thread's name
    QThread *thread = QThread::currentThread();
    thread->setObjectName("Main Thread");

    // Generate a random maximum value for the loop
    int max = QRandomGenerator::global()->bounded(10);
    QProcess process;  // Single process instance
    // Start the process once if it is not running
    if (process.state() != QProcess::Running) {
        process.start("cmd");
    }
    for (int i = 0; i < max; i++)
    {
        if (i % 2 == 0) {
            qInfo() << i << "on ->" << thread->objectName();
        }

    }
    // Terminate the process after a delay
    QTimer::singleShot(max*1000, [&process]() {
        if (process.state() == QProcess::Running) {
            process.terminate();  // Attempt to terminate
            qInfo() << "Process terminated.";
        }
    });
    qInfo() << "Thread Finished!";
    qInfo() << "Max value: " << max;

    return a.exec();
}
