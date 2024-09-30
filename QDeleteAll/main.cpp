#include <QCoreApplication>
#include <QDebug>
#include "listclass.h"
#include <QList>
#include<iostream>
// Declare a type alias for QList<ListClass*> for convenience
using ItemList = QList<ListClass*>;

// Function to create and return a QList of ListClass pointers
ItemList getItem()
{
    ItemList list;  // Declare QList normally
    for (int i = 0; i < 5; i++)
    {
        ListClass* item = new ListClass();  // Create a new ListClass object
        item->setObjectName(QString("Item %1").arg(i));  // Set object name
        list.append(item);  // Add it to the list
    }
    return list;
}

// Function to display the contents of the list
void Display(ItemList list)
{
    foreach (ListClass* item, list)  // Iterate through the list
    {
        qInfo() << item << "Name:" << item->objectName();  // Print object info and name
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Get the list of items
    ItemList items = getItem();  // Call getItem to create and return the list
    std::cout<<"\n";
    Display(items);  // Display the list

    std::cout<<"\n";
    //qDeleteAll(items);
    qDeleteAll(items.begin(), items.end());
    items.clear();


    return a.exec();
}
