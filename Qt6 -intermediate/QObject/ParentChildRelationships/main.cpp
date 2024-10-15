#include <QCoreApplication>
#include <QDebug>
#include "myobject.h"

MyObject* ParentChild()
{
    MyObject *root = new MyObject(nullptr, "Parent");

    for(int i = 0; i < 3; i++)
    {
        MyObject* child = new MyObject(root, "Child " + QString::number(i));
        for(int j = 0; j < 1; j++)
        {
            MyObject* grandchild = new MyObject(child, "GrandChild " + QString::number(i));
        }
    }
    return root;
}

void Print(MyObject *root, int level = 0)
{
    // Generate indent based on the level
    QString indent;
    if (level == 0) {
        indent = ""; // Root level, no indent
    } else if (level == 1) {
        indent = "    |        "; // Child level
    } else if (level == 2) {
        indent = "        |----"; // Grandchild level
    }

    // Print current object name
    if (level == 0) {
        qDebug().noquote() << root->objectName();
        qDebug().noquote() << "  |";
        qDebug().noquote() << "-----------------------------------------------------";
    } else {
        qDebug().noquote() << indent << root->objectName();
    }

    // Recursively print all children with proper formatting
    for(QObject* child : root->children())
    {
        Print(qobject_cast<MyObject*>(child), level + 1);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Build the hierarchy
    MyObject *root = ParentChild();

    // Print the hierarchy
    Print(root);

    // Clean up
    delete root;

    return a.exec();
}
