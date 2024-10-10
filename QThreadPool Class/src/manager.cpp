#include "../header/manager.h"
#include "../header//developer.h"
#include <QDebug>
#include <QThreadPool>

Manager::Manager(QObject *parent) : QObject(parent) {
    // Constructor implementation if needed
}

void Manager::assignTask() {
    Developer *developer = new Developer();

    connect(developer, &Developer::started, this, []() {
        qDebug() << "Developer started task.";
    });
    connect(developer, &Developer::finished, this, &Manager::onTaskFinished);

    developer->dev(); // Trigger the task
}

void Manager::onTaskFinished() {
    qDebug() << "Task completed. Cleaning up...";
    Developer *developer = qobject_cast<Developer*>(sender()); // Get the sender as Developer
    if (developer) {
        developer->deleteLater(); // Safely delete the developer object
    }
}
