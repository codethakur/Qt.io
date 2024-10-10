#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QObject>
#include <QRunnable>

class Developer : public QObject, public QRunnable {
    Q_OBJECT

public:
    Developer();
    ~Developer();

public slots:
    void dev(); // Slot to handle task initialization

protected:
    void run() override; // Overriding QRunnable's run function for task execution

signals:
    void started();  // Signal emitted when the task starts
    void finished(); // Signal emitted when the task finishes
};

#endif // DEVELOPER_H
