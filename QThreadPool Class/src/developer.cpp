#include "../header/developer.h"
#include <QDebug>
#include <QThread>
#include <QThreadPool>

Developer::Developer() {
    setAutoDelete(true); // Ensures that QRunnable deletes itself after execution
    qDebug() << "Developer created:" << this;
}

Developer::~Developer() {
    qDebug() << "Developer destroyed:" << this;
}

void Developer::dev() {
    // Start the task by queuing it on the global thread pool
    QThreadPool::globalInstance()->start(this);
}

void Developer::run() {
    emit started(); // Emit started signal when task begins
    qDebug() << "Started task on developer" << this << QThread::currentThread();

    for (int i = 0; i < 5; ++i) {
        qDebug() << "Developing..." << this << QThread::currentThread();
        QThread::sleep(1); // Simulate work
    }

    emit finished(); // Emit finished signal when task completes
    qDebug() << "Finished task on developer" << this << QThread::currentThread();
}
