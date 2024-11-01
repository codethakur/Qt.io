#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QDebug>

int longRunningTask(int number)
{
    QThread::sleep(2);
    return number * number;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess process;
    process.start("some_external_command");


    QFuture<int> future = QtConcurrent::run(longRunningTask, 5);

    QFutureWatcher<int> watcher;

    QObject::connect(&watcher, &QFutureWatcher<int>::finished, [=, &a]() {
        qInfo() << "Result:" << future.result();
        a.quit();
    });
    // QObject::connect(&watcher, &QFutureWatcher<int>::finished, [&process]() {
    //     qInfo() << "Finished long-running task. Terminating external process.";
    //     process.terminate();  // Terminates the external process
    // });




    watcher.setFuture(future);

    return a.exec();
}
