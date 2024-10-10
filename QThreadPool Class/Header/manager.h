#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class Manager : public QObject {
    Q_OBJECT

public:
    explicit Manager(QObject *parent = nullptr);

signals:
    void dev(); // Signal to initiate a task assignment

public slots:
    void assignTask();     // Slot connected to `dev()` to assign a task
    void onTaskFinished(); // Slot to handle task completion

};

#endif // MANAGER_H
