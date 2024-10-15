#include "test.h"
#include<QDebug>



test::test(QObject *parent)
{
    qInfo()<<"Construtor called\n";
}

test::~test()
{
 qInfo()<<"Deconstrutor called\n";
}

void test::testing()
{
    QString sound = "Wake Up!!";
    emit alram(sound);
}

void test::weakup(QString Sound)
{
    qInfo()<<"From"<<sender()<<Sound;
}
