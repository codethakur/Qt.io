// vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <QVector>
#include <QDebug>

class VectorOperations {
public:
    VectorOperations();
    void initializeVector();
    void appendElements();
    void accessElements();
    void modifyElements();
    void searchElements();
    void countOccurrences();
    void removeElements();
    void clearVector();
    void addRange();
    void displaySize();

private:
    QVector<int> vector;
    void displayVector(const QString& message);
};

#endif // VECTOR_H
