#include "timeclass.h"

TimeClass::TimeClass(QObject *parent): QObject{parent}
{
    number =0;
    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout, this, &TimeClass::timeout);
}

void TimeClass::timeout()
{
    number++;
 //   qInfo()<<QTime::currentTime().toString(Qt::DateFormat::TextDate);
    qInfo() << QTime::currentTime().toString("hh:mm:ss AP");
    if(number>=5){
        timer.stop();
        qInfo()<<"Timeout!";
    }
}

void TimeClass::timestart()
{
    number =0;
    timer.start();
}
