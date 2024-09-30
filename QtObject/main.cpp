#include <QCoreApplication>
#include "testclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestClass test;
    QObject::connect(&test,&TestClass::close,&a,&QCoreApplication::quit,Qt::QueuedConnection);
    test.log();

    return a.exec();
}
