#include <QCoreApplication>
#include<QTimer>
#include "timeclass.h"
#include"filedirwatcher.h"

void Wait()
{
    qInfo()<<"Thank you for wait..!";
}
int main(int argc, char *argv[])
{
     QCoreApplication a(argc, argv);

    FileDirWatcher fsw;



     // TimeClass time;
     // time.timestart();
    // qInfo()<<"Please wait..\n";

    // QTimer::singleShot(5000, Wait);

    return a.exec();
}
