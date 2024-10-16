#include <QCoreApplication>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QWeakPointer>
#include <QDebug>
#include "entity.h"

void ScopePtr() {
    QScopedPointer<Entity> ScoPtr(new Entity());
    ScoPtr->setObjectName("Scope Pointer");

    qInfo() << "QScopedPointer Address:" << &ScoPtr;
    qInfo() << "Entity Object Address:" << ScoPtr.data();
    qInfo() << "Entity Object Name:" << ScoPtr->objectName() << "\n";
}

void SharPtr() {
    QSharedPointer<Entity> SharPtr1(new Entity());
    SharPtr1->setObjectName("Shared Pointer1");

    qInfo() << "QSharedPointer1 Address:" << &SharPtr1;
    qInfo() << "Entity Object Address (SharPtr1):" << SharPtr1.data();
    qInfo() << "Entity Object Name (SharPtr1):" << SharPtr1->objectName();

    qInfo() << "------------------------------------------";
    QSharedPointer<Entity> SharPtr2 = SharPtr1;
    qInfo() << "QSharedPointer2 Address:" << &SharPtr2;
    qInfo() << "Entity Object Address (SharPtr2):" << SharPtr2.data();
    qInfo() << "Entity Object Name (SharPtr2):" << SharPtr2->objectName() << "\n";

    QWeakPointer<Entity> weakPtr(SharPtr2);
    qInfo() << "QWeakPointer Address:" << &weakPtr;

    if (auto strongRef = weakPtr.toStrongRef()) {
        qInfo() << "Entity Object Address (weakPtr):" << strongRef.data();
        qInfo() << "Entity Object Name (weakPtr):" << strongRef->objectName();
    } else {
        qInfo() << "The weak pointer does not refer to a valid object.";
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    ScopePtr();
    qInfo() << "------------------------------------------\n";
    SharPtr();
    return a.exec();
}
