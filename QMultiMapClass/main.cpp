#include <QCoreApplication>
#include <QDebug>
#include <QMap>
#include <QRandomGenerator>
#include "mapclass.h"

typedef QMap<QString, QSharedPointer<MapClass>> EmpMap;

EmpMap getEMp()
{
    EmpMap map;
    QStringList employeeNames = {"John", "Alice", "Bob", "Charlie", "Eve"};
    for (int i = 0; i < 5; i++)
    {
        QSharedPointer<MapClass> ptr(new MapClass());
        ptr->SetId(QRandomGenerator::global()->bounded(1000, 5000));
        ptr->SetName(employeeNames.at(i)); // Assign a unique name from the list
        map.insert("Emp" + QString::number(i), ptr);
    }
    return map;
}

void displayEmp(const EmpMap& Map)
{
    foreach (const QString& key, Map.keys()) {
        QSharedPointer<MapClass> employee = Map.value(key);
        qInfo() << "Key:" << key << "Id:" << employee->id() << "Name:" << employee->name();
    }
}

void ModifyEmp(EmpMap &emp, const QString &key)
{
    if(emp.contains(key))
    {
        qInfo() << "\nModify:" << key << "\n";
        emp[key]->SetId(700);
        emp[key]->SetName("Hemsworth");
        displayEmp(emp);
    }
}

void SearchEmp(const EmpMap &empmap, const QString &key = "",
               int id = -1, const QString &name = "")
{
    bool found = false;

    foreach (const QString &mapKey, empmap.keys()) {
        QSharedPointer<MapClass> employee = empmap.value(mapKey);

        // Check ID
        if (id != -1 && employee->id() == id) {
            qInfo() << "Found Employee by Id: " << "Key:" << mapKey
                    << "Id:" << employee->id() << "Name:" << employee->name();
            found = true;
        }

        // Check Key
        if (!key.isEmpty() && mapKey == key) {
            qInfo() << "Found Employee by Key: " << "Key:" << mapKey
                    << "Id:" << employee->id() << "Name:" << employee->name();
            found = true;
        }

        // Check Name
        if (!name.isEmpty() && employee->name() == name) {
            qInfo() << "Found Employee by Name: " << "Key:" << mapKey
                    << "Id:" << employee->id() << "Name:" << employee->name();
            found = true;
        }
    }

    if (!found) {
        qInfo() << "Employee not found with the provided criteria.";
    }
}

void userInputSearch(const EmpMap &empmap)
{
    QTextStream input(stdin);  // To read user input
    QString key;
    int id = -1;
    QString name;

    // Ask user for key input
    qInfo() << "\nEnter Employee Key (or press Enter to skip): ";
    key = input.readLine();

    // Ask user for ID

    qInfo() << "Enter Employee ID (or press Enter to skip): ";
    QString idStr = input.readLine();
#if 0
    if (!idStr.isEmpty()) {
        id = idStr.toInt();
    }
#endif
    bool isInt;
    id = idStr.toInt(&isInt); // isInt will be set to true if conversion is successful
    if (!isInt && !idStr.isEmpty()) {
        qWarning() << "Invalid ID entered. Please enter a valid integer.";
        id = -1; // Reset to -1 if invalid input is entered
    }

    // Ask user for name input
    qInfo() << "Enter Employee Name (or press Enter to skip): ";
    name = input.readLine();

    // Perform the search
    SearchEmp(empmap, key, id, name);
}

void AddEmploye(EmpMap &newEmpmap)
{
    QSharedPointer<MapClass> employe(new MapClass());
    employe->SetId(100);
    employe->SetName("Chris");
    newEmpmap.insert("Intern", employe);
    displayEmp(newEmpmap);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EmpMap empmap = getEMp();
    displayEmp(empmap);

    qInfo() << "\nNow you can search for an employee.";

    // Allow user to search multiple times
    char continueSearch = 'y';
    QTextStream input(stdin);

    while (continueSearch == 'y' || continueSearch == 'Y') {
        userInputSearch(empmap);

        qInfo() << "\nDo you want to search again? (y/n): ";
        input >> continueSearch;
        input.readLine();  // Clear the input buffer
    }

    return a.exec();
}

