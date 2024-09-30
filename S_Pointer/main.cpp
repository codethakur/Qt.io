#include <QCoreApplication>
#include <QScopedPointer>
#include <QSharedPointer>
#include "ptrclsss.h"

void ScopePtr()
{
    QScopedPointer<ptrClsss> ptr(new ptrClsss());
    ptr->message("QScopedPointer");
}

void workDone(QSharedPointer<ptrClsss>& ptr) // Pass by reference
{
    ptr->message("workDone!");
}

void working(QSharedPointer<ptrClsss>& ptr)
{
    ptr->message("working");
}

void progress(QSharedPointer<ptrClsss>& ptr)
{
    ptr->message("progressing...");
    for (int i = 0; i < 10; i++) {
        working(ptr);
    }
    workDone(ptr);
}

void SharedPtr(ptrClsss* R_ptr)
{
    //QSharedPointer<ptrClsss> ptr(new ptrClsss()); // Create a valid shared pointer
    QSharedPointer<ptrClsss> ptr(R_ptr);
    ptr->message("QSharedPointer");

    progress(ptr); // Use the shared pointer across functions
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ScopePtr();
    SharedPtr(new ptrClsss());

    return a.exec();
}
