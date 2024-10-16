#ifndef LIST_H
#define LIST_H

#include <QList>
#include <QDebug>

class ListOperations {
public:
    ListOperations();
    void initializeList();
    void appendElements();
    void prependElements();
    void insertElement();
    void accessElements();
    void modifyElements();
    void checkContains();
    void getIndex();
    void countOccurrences();
    void removeElements();
    void clearList();
    void addRange();
    void displaySize();

private:
    QList<int> list;
    void displayList(const QString& message);
};

#endif // LIST_H
