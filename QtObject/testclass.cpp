#include "testclass.h"

TestClass::TestClass(QObject *parent)
    : QObject{parent}
{}

void TestClass::log()
{
    qInfo() <<"Hello from testClass CPP! ";
    emit close();
}
