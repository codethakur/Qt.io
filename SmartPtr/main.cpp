#include <QCoreApplication>
#include <QSharedPointer>
#include <QWeakPointer>
#include"entity.h"


void ScopePtr()
{
    QScopedPointer<Entity> ScoPtr(new Entity());
    ScoPtr->setObjectName("Scope Pointer");

    // Print the address of the QScopedPointer and the name of the Entity object
    qInfo() << "QScopedPointer Address:" << &ScoPtr;
    qInfo() << "Entity Object Address:" << ScoPtr.data(); // .data() gives the raw pointer
    qInfo() << "Entity Object Name:" << ScoPtr->objectName()<<"\n";
}


void SharPtr()
{
    QSharedPointer<Entity> SharPtr1(new Entity());
    SharPtr1->setObjectName("Shared Pointer1");

    qInfo() << "QSharedPointer1 Address:" << &SharPtr1;
    qInfo() << "Entity Object Address (SharPtr1):" << SharPtr1.data();
    qInfo() << "Entity Object Name (SharPtr1):" << SharPtr1->objectName();

    qInfo()<<"------------------------------------------\n";
    QSharedPointer<Entity> SharPtr2 = SharPtr1;
    //SharPtr2->setObjectName("Shared Pointer2");

    qInfo() << "QSharedPointer2 Address:" << &SharPtr2;
    qInfo() << "Entity Object Address (SharPtr2):" << SharPtr2.data(); // Same address as SharPtr1
    qInfo() << "Entity Object Name (SharPtr2):" << SharPtr2->objectName() << "\n";

    qInfo()<<"------------------------------------------\n";
    //qInfo() << "Entity Object Name after changed (SharPtr1):" << SharPtr1->objectName();
    if (SharPtr1.isNull()) {
        qInfo() << "SharPtr1 is null.";
    } else {
        qInfo() << "SharPtr1 is valid.";
    }
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    SharPtr();

    return a.exec();
}
