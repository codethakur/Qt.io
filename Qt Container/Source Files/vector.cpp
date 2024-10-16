// vector.cpp
#include "vector.h"

VectorOperations::VectorOperations() {}

void VectorOperations::initializeVector() {
    vector << 1 << 2 << 3;
    displayVector("Initial vector:");
}

void VectorOperations::appendElements() {
    vector.append(4);
    vector.append(5);
    displayVector("After appending 4 and 5:");
}

void VectorOperations::accessElements() {
    qInfo() << "First element:" << vector.first();
    qInfo() << "Last element:" << vector.last();
    qInfo() << "Element at index 2:" << vector.at(2) << "\n--------";
}

void VectorOperations::modifyElements() {
    vector[2] = 100;  // Using operator[]
    vector.replace(3, 101);  // Using replace()
    displayVector("After modifying elements:");
}

void VectorOperations::searchElements() {
    qInfo() << "Contains 3?" << vector.contains(3);
    qInfo() << "Contains 99?" << vector.contains(99) << "\n--------";
}

void VectorOperations::countOccurrences() {
    vector.append(1); // Adding duplicate elements
    vector.append(1);
    displayVector("Vector after adding duplicates:");
    qInfo() << "Count of 1:" << vector.count(1) << "\n--------";
}

void VectorOperations::removeElements() {
    vector.removeAt(0); // Remove element at index 0
    vector.removeOne(100); // Remove first occurrence of 100
    qInfo() << "After removing elements:" << vector << "\n--------";
}

void VectorOperations::clearVector() {
    vector.clear();
    displayVector("After clearing the vector:");
}

void VectorOperations::addRange() {
    for (int i = 1; i <= 5; ++i) {
        vector << i;
    }
    displayVector("Vector after adding a range of elements:");
}

void VectorOperations::displaySize() {
    qInfo() << "Vector size:" << vector.size();
}

void VectorOperations::displayVector(const QString& message) {
    qInfo() << message << vector << "\n--------";
}
