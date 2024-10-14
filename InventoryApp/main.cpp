#include <QCoreApplication>
#include<QTextStream>
#include "inventoryclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    InventoryClass inventory;

    qInfo()<<"Choose an option:";
    qInfo()<<"add <name><key>";
    qInfo()<<"remove <name><key>";
    qInfo()<<"Save";
    qInfo()<<"Load";
    qInfo()<<"list";
    qInfo()<<"Quit";

    QTextStream stream(stdin);

    while(true)
    {
        qInfo() << "Enter Option: ";
        QString line = stream.readLine();
        QStringList list = line.split(" ");

        if(list.size() < 1) break;

        QString option = list.at(0).toUpper();

        if(option == "QUIT") {
            break;
        }
        if(option == "LIST") inventory.list();
        if(option == "LOAD") inventory.load();
        if(option == "SAVE") inventory.save();

        if(option == "ADD" || option == "REMOVE") {
            // Check if required inputs are missing
            if(list.size() < 3) {
                qWarning() << "Not enough info. Please enter in the format: add <name> <quantity>";
                continue; // Restart the loop to prompt for the full command again
            }

            QString name = list.at(1);
            bool okay;
            int Qty = list.at(2).toInt(&okay);

            if(!okay) {
                qWarning() << "Invalid quantity!";
                continue;
            }

            if(option == "ADD") inventory.add(name, Qty);
            if(option == "REMOVE") inventory.remove(name, Qty);
        }
    }

    inventory.save();
    qInfo()<<"Completed!";


   // return a.exec();
    return 0;
}
