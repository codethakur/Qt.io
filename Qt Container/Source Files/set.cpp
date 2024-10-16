#include "set.h"

SetOperations::SetOperations() {
    // Constructor - No specific initialization needed for QSet
}

void SetOperations::insert(int value) {
    set.insert(value);
}

void SetOperations::remove(int value)
{
    set.remove(value);
}

bool SetOperations::contains(int value) const
{
    return set.contains(value);
}

int SetOperations::size() const
{
    return set.size();
}

void SetOperations::clear()
{
    // int n = set.size();
    // for(int i=0; i<=n; i++)
    // {
    //     set.remove(i);
    // }
    set.clear();
}

QSet<int> SetOperations::getUnion(const QSet<int>& otherSet) const {
    //return set.united(otherSet);
    return set | otherSet;
}



QSet<int> SetOperations::getIntersection(const QSet<int>& otherSet) const {
   // return set.intersected(otherSet);
    return set & otherSet; // Using the intersection operator
}

QSet<int> SetOperations::getDifference(const QSet<int>& otherSet) const {
    //return set.subtracted(otherSet);
    return set - otherSet; // Using the subtraction operator
}


void SetOperations::printSet() const {
    qDebug()<< "Set contents:" << set;
}


const QSet<int>& SetOperations::getSet() const {
    return set;
}
