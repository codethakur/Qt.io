#include <QCoreApplication>
#include"test.h"



void Notification()
{
    test Clock;
    test message;

    Clock.setObjectName("Alram Clock");
    message.setObjectName("Message");

    QObject::connect(&Clock, &test::alram, &message, &test::weakup, Qt::ConnectionType::AutoConnection);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Notification();


    return a.exec();
}
