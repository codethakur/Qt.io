#include <QCoreApplication>
#include <QList>
#include <QRandomGenerator>
#include <iostream>
#include "listclass.h"

QList<int> getNumber()
{
    QList<int> list;
    int max = QRandomGenerator::global()->bounded(1, 10);

    for (int i = 0; i < max; i++)
    {
        list.append(QRandomGenerator::global()->bounded(1, 100));
    }
    return list;
}
void testNumber()
{
    QList<int>list=getNumber();
    qInfo()<<"list from testNumber"<< list;
    std::cout<<"Length: "<<list.length()<<std::endl;

    for(int i=0; i<list.length(); i++)
    {
        qInfo()<<i<<" = "<<list.at(i)<< " ["<<list[i]<<"]";
    }

}
void modifylist()
{
    QList<int>list=getNumber();
    qInfo()<<list;
    list[0]=100;
    qInfo()<<"list[0]=100"<<list;
    list.append(105);
    qInfo()<<"list.append(105)"<<list;
    qInfo()<<"---------------------------------";
    list.insert(1, 456);
    list.insert(1, 456);
    list.insert(1, 456);
    list.insert(1, 456);
    list.insert(1, 456);
    qInfo()<<list;
    qInfo()<<"---------------------------------";
    list.remove(1,2);
    qInfo()<<list;
    qInfo()<<"---------------------------------";
    list.removeOne(456);
    qInfo()<<"---------------------------------";
    list.removeAll(456);
    qInfo()<<list;
    qInfo()<<"---------------------------------";


}

void SearchItem()
{
    QList<int>list;
    int item = 911;
    list.insert(0,item);
    list.insert(1,item);
    list.insert(2,item);
    list.insert(2,item);
   // list.append(item);
    qInfo()<<"Length: "<<list.length()<<"\n";

    for(int i=0; i<list.length(); i++)
    {
        qInfo()<<i<<" = "<<list.at(i)<< " ["<<list[i]<<"]";
    }
    int  firstPosition = list.indexOf(item);
    int lastPosition = list.lastIndexOf(item);

    qInfo()<<"firstPosition of item "<<firstPosition<<" and lastPosition "<<lastPosition;

    int pos= list.indexOf(item);
    do{
        qInfo()<<"At: "<<pos;
        pos = list.indexOf(item, pos+1);
    }while(pos>-1);
    qInfo()<<"pos "<<pos;

    int number =100;
    qInfo()<<"item contains: "<<list.contains(item);

    qInfo()<<"number contains: "<<list.contains(number);
}

void Objectptr()
{
    QList<ListClass*> list;
    for (int i = 0; i < 10; i++)
    {
        list.append(new ListClass());
    }

    qInfo() << "CleanUP:";
    qDeleteAll(list);
    list.clear();

    qInfo() << list.length();
}

void ObjectSptr()
{
    QList<QSharedPointer<ListClass>> list;
    for (int i = 0; i < 10; i++)
    {
        QSharedPointer<ListClass> item(new ListClass);
        list.append(item);
    }

    qInfo() << "List contains" << list.length() << "items.";

    list.clear();
    qInfo() << "After clear, list contains" << list.length() << "items.";
}

void ObjectSptr2()
{
    QList<QSharedPointer<ListClass>> list;
    for (int i = 0; i < 10; i++)
    {
        list.append(QSharedPointer<ListClass>::create());  // More efficient way to create and append
    }

    qInfo() << "List contains" << list.length() << "items.";

    list.clear();  // Clears the list and destroys the objects if no more references exist

    qInfo() << "After clear, list contains" << list.length() << "items.";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#if 0

    // QList<int> list = getNumber();  // Capture the returned list from getNumber()

    // // Print the generated random numbers
    // std::cout << "Generated numbers: ";
    // for (int num : list) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
#endif

    ObjectSptr2();
    return a.exec();  // Starts the event loop for the application
}
