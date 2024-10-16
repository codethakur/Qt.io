#include "list.h"

ListOperations::ListOperations() {}

void ListOperations::initializeList() {
    list << 1 << 2 << 3;
    displayList("Initial list:");
}

void ListOperations::appendElements() {
    list.append(4);
    list.append(5);
    displayList("After appending 4 and 5:");
}

void ListOperations::prependElements() {
    list.prepend(0);
    displayList("After prepending 0:");
}

void ListOperations::insertElement() {
    list.insert(2, 99);
    displayList("After inserting 99 at index 2:");
}

void ListOperations::accessElements() {
    qInfo() << "First element:" << list.first();
    qInfo() << "Last element:" << list.last();
    qInfo() << "Element at index 2:" << list.at(2) << "\n--------";
}

void ListOperations::modifyElements() {
    list[2] = 100;
    list.replace(3, 101);
    displayList("After modifying elements:");
}



void ListOperations::getIndex() {
    qInfo() << "Index of 100:" << list.indexOf(100);
    qInfo() << "Last index of 101:" << list.lastIndexOf(101) << "\n--------";
}

void ListOperations::countOccurrences() {
    list.append(1);
    list.append(1);
    displayList("List after adding duplicates:");
    qInfo() << "Count of 1:" << list.count(1) << "\n--------";
}

void ListOperations::removeElements() {
    list.removeAt(0);
    list.removeOne(100);
    list.removeAll(1);
    displayList("After removing elements:");
}

void ListOperations::clearList() {
    list.clear();
    displayList("After clearing the list:");
}

void ListOperations::addRange() {
    for (int i = 1; i <= 5; ++i) {
        list << i;
    }
    displayList("List after adding a range of elements:");
}

void ListOperations::displaySize() {
    qInfo() << "List size:" << list.size();
}

void ListOperations::displayList(const QString& message) {
    qInfo() << message << list << "\n--------";
}
