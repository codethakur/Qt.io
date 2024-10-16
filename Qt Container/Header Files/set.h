
#ifndef SET_H
#define SET_H

#include <QSet>
#include <QDebug>

class SetOperations {
public:
    SetOperations();
    void insert(int value);
    void remove(int value);
    bool contains(int value) const;
    int size() const;
    void clear();
    QSet<int> getUnion(const QSet<int>& otherSet) const;
    QSet<int> getIntersection(const QSet<int>& otherSet) const;
    QSet<int> getDifference(const QSet<int>& otherSet) const;
    void printSet() const;

public:
    const QSet<int>& getSet() const; // Getter for accessing the private set

private:
    QSet<int> set;
};

#endif // SET_H
