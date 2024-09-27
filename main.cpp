#include <QCoreApplication>
#include <iostream>
#include <string>
#include<QTextStream>
#include<QDebug>

void HelloWorld()
{
    std::string name;
    std::cout << "Enter your name: \n";
    std::getline(std::cin, name);
    std::cout << "Hello! " << name <<" from C++."<< "\n";
    std::cout << "------------\n";
}


void HelloWorldQT()
{


    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout<< "Enter your name: \n";
    qout.flush();
    //std::getline(std::cin, name);
    QString name = qin.readLine();
    qout<<"Hello! "<<name<<"from QT. "<<"\n";
    qout.flush();
}
void HelleoWorldQtCPP()
{
    QTextStream qin(stdin);
    qInfo()<<"Enter you language: ";
    QString language = qin.readLine();

    qInfo()<<"You language is: "<<language;

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // HelloWorld();
    // HelloWorldQT();
    HelleoWorldQtCPP();

    return a.exec();
    //return 0;
   // std::cin.get();
}
