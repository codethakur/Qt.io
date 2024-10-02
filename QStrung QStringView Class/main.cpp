#include <QCoreApplication>
#include<iostream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QDebug>

void PrintName(QString Name)
{
    qInfo()<<Name<<Name.data();
}
void refName(QString &Name)
{
    Name.insert(0,"Mr. ");
    qInfo()<<Name<<Name.data();
}

void ReadName(QStringView Name)
{
    qInfo()<<Name<<Name.data();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "Hello, World!";
    /* qInfo() << "Hello From QT!\nfrom debug";

    qInfo() <<str;

    int page = 100;
    int  chapter = 6;
    QString line= QString("Timeless Lessons on Risk:  %1, %2").arg(chapter).arg(page);
    qInfo()<<"line: "<<line;

    qInfo("separate the individual characters from a string");
    for(int i=0; i<str.length(); i++)
    {
        QChar ch = str.at(i);
        qInfo()<<ch;
    }

    qInfo()<<"Compare and Search QString! ";
    QString Hello_str = "Hello";
    qInfo()<<"CaseSensitive" << Hello_str.compare("hello", Qt::CaseSensitive);   // Output will be > 0 (non-zero), because 'H' ≠ 'h'
    qInfo()<<"CaseInsensitive" << Hello_str.compare("hello", Qt::CaseInsensitive); // Output will be 0, because 'H' == 'h' when case is ignored
    qInfo()<<"End With CaseInsensitive "<<Hello_str.endsWith("hello", Qt::CaseInsensitive);
    qInfo()<<"End With CaseSensitive "<<Hello_str.endsWith("hello", Qt::CaseSensitive);
    qInfo()<<"starts With CaseSensitive "<<Hello_str.startsWith("hello", Qt::CaseSensitive);


    qInfo()<<"Qt, parsing";

    qDebug("Splitting a QString");

    QString Numstr1 = "one, two, three, four";
    QStringList list = Numstr1.split(",");
    qDebug()<<"Numstr1"<<list;

    QString Numstr2 = "one,,three,four";
    QStringList list2 = Numstr2.split(",", Qt::SkipEmptyParts);
    qDebug()<<"Numstr2"<<list2;

    qInfo()<<"Extracting Substrings";

    QString SUb_Str = "Hello, World";

    QString left = SUb_Str.left(5);
    QString mid =  SUb_Str.mid(7,5);
    QString right = SUb_Str.right(6);
    qInfo()<<"left: "<<left<<"\nmid: "<<mid<<"\nright"<<right;

    qInfo()<<"\nConverting QString to Number";

    QString StrNum = "121";
    int number = StrNum.toInt();
    qInfo()<<"StrNum into number: "<<number;


    bool flag = true;
    QString StrAndNum = "121abc";
    int Str = StrAndNum.toInt(&flag);
    qInfo()<<Str <<flag;

    int index = str.indexOf("World");
    int lastIndex = str.lastIndexOf("o");

    qInfo()<<"Index of  World"<<index<<"lastIndex of O"<<lastIndex;

    QRegularExpression re("(\\d+)");
    QString Itemstr = "Item 42, Item 1337, Item 99";
    QRegularExpressionMatchIterator i = re.globalMatch(Itemstr);

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        qDebug() << "Found number:" << match.captured(0);
    }
    */


    QString FullName = "Kishan Thakur";
#if 0
    // Extract first name (first 6 characters)
    QStringView fname(FullName);
    fname = fname.mid(0, 6);

    // Extract last name (from position 7 to 6 characters)
    QStringView sname(FullName);
    sname = sname.mid(7, 6);

    // qInfo() << "First Name:" << fname;
    // qInfo() << "Last Name:" << sname;
#endif

    QString FName= "Kishan";
    QString SName= "Thakur";

    PrintName(FName);
    qInfo()<<"Original String: "<<FName<<FName.data();

    QString OriginalFName = FName;  // Create a copy of the original string.

    qInfo() << "------------------------------\n";
    refName(FName);  // Modify the original string "FName"
    qInfo() << "Original String: " << FName << FName.data();  // "Mr. Kishan"

    qInfo() << "------------------------------\n";
    ReadName(OriginalFName);  // Pass the original unmodified copy to ReadName.
    qInfo() << "Original String: " << FName << FName.data();  // "Mr. Kishan"








}
