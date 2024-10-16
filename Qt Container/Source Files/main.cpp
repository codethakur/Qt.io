#include <QCoreApplication>
#include "list.h"
#include "vector.h"
#include"set.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SetOperations setOps;

    setOps.insert(0);
    for(int i=1; i<6; i++ )
    {
        setOps.insert(i);
    }
    setOps.remove(1);
    setOps.clear();

    for(int i=0; i<10; i++)
    {
        if(i%2==0){
            setOps.insert(i);
        }
    }

    setOps.printSet();


    SetOperations otherSetOps;
    for(int i=0; i<10; i++)
    {
        if(i%3==0){
            otherSetOps.insert(i);
        }
    }
    otherSetOps.printSet();

    QSet<int> unionSet = setOps.getUnion(otherSetOps.getSet());

    QSet<int> intersectionSet = setOps.getIntersection(otherSetOps.getSet());
    QSet<int> differenceSet = setOps.getDifference(otherSetOps.getSet());

    qDebug() << "Union with other set:" << unionSet;
    qDebug() << "Intersection with other set:" << intersectionSet;
    qDebug() << "Difference from other set:" << differenceSet;





    return a.exec();
}
