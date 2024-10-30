#include <QCoreApplication>
#include<QTimer>

void Wait()
{
    qInfo()<<"Thank you for wait..!";
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<<"Please wait..\n";

    QTimer::singleShot(5000, Wait);

    return a.exec();
}
