#include <QCoreApplication>
#include <QByteArray>
#include<QDebug>

void DisplayArr(QByteArray qArr)
{
    qDebug()<<"Length of QByteArray "<<qArr.length()<<"and Capacity"<<qArr.capacity();
    qDebug()<<qArr;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);




    QByteArray byteArr("Hello, QT!");
    #if 0
    qDebug()<<byteArr;

    QByteArray upperCase = byteArr.toUpper();
    qDebug()<<"Upper Case: "<<upperCase;

    int index = byteArr.indexOf("QT");
    qDebug()<<"index of QT: "<<index;

    QByteArray buffer(10,'-');
    qDebug()<<"Buffer: "<<buffer;

    DisplayArr(byteArr);
    qDebug()<<"----------reserve(5)---------------";
   // byteArr.reserve(5);
    DisplayArr(byteArr);
    qDebug()<<"-------------reserve(20)-----------";
    //byteArr.reserve(20);
    DisplayArr(byteArr);
    qDebug()<<"--------------------------------";

    byteArr.replace(0,100,"C++");
    DisplayArr(byteArr);

    int FirstIndex = byteArr.indexOf("l");
    int lastIndex = byteArr.lastIndexOf("l");
    qDebug()<<"FirstIndex of  l "<<FirstIndex<<" lastIndex "<<lastIndex;
    qDebug()<<byteArr;


    byteArr.prepend("***");
    byteArr.append("***");
    int firstIndex = byteArr.indexOf("*");
    int lastIndex = byteArr.lastIndexOf("*");

    qDebug()<<"firstIndex of * "<<firstIndex<<"lastIndexof *"<<lastIndex<<"\n"<<byteArr;
    int length = lastIndex - firstIndex + 1;  // Calculate length of the section to extract
   // QByteArray midSection = byteArr.mid(firstIndex, length);  // Extract the section
      int midIndex = (firstIndex + lastIndex) / 2;

    qDebug() << "Mid index of *:" << midIndex;
    qDebug() << "Character at mid index:" << byteArr[midIndex];

#endif

    // for(int i=0; i<byteArr.length(); i++)
    // {
    //     qDebug()<<"At"<<byteArr.at(i)<<" oR"<<byteArr[i]<<" "<<byteArr[8];
    // }
    foreach (auto ch, byteArr.split(' ')) {
        qDebug()<<ch;
    }




  return a.exec();
}
