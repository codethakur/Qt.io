#include <QCoreApplication>
#include "objectclass.h"

void Object(ObjectClass obj)
{
    qInfo() << "Object";

}

void ObjectRef(const ObjectClass &obj)
{
    qInfo() << " Pass by const reference to avoid copying";

}
void ObjectPtr(ObjectClass *obj)
{
    qInfo() << "Pass by pointer to avoid copying";

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ObjectClass obj1;
    //Object(obj1);   // No slicing or copying happens here


    //prevent an object from being copied!
    ObjectRef(obj1);
    ObjectPtr(&obj1);


    return a.exec();
}
