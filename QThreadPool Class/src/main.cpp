#include <QCoreApplication>
#include "../header/manager.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Manager manager;
    manager.assignTask();

    return app.exec();
}
