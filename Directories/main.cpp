#include <QCoreApplication>
#include<QDir>
#include<QFileInfo>
#include<QFileInfoList>
#include <QTimer>

void CurrPath()
{
    qInfo()<<QDir::currentPath();

    QDir dir;
    qInfo()<<dir.absolutePath();
}

void PathFind(QString path, bool recursive = false)
{
    QDir root(path);
    if (!root.exists()) {
        qInfo() << "404!";
        return;
    }
    qInfo() << "Directory exists at: " << root.absolutePath();
    qInfo()<<"------------------------------------------------\n";

    QFileInfoList list = root.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries);
    foreach (QFileInfo fi, list) {
        qInfo()<<"--------------------\n";
        qInfo()<<"Name: "<<fi.fileName();
        qInfo()<<"Path: "<<fi.path();
        qInfo()<<"Absolute: "<<fi.absoluteFilePath();
        qInfo()<<"Creted: "<<fi.birthTime().toString();
        qInfo()<<"Size: "<<fi.size();


        QString type = "Unknow";
        fi.isDir() ? type = "Dir" : "File";
        qInfo()<<"Type-> "<<type;

        if(recursive && fi.isDir()) PathFind(fi.absoluteFilePath());


    }
}

void modifyFile(QDir root)
{
    root.setPath("A:/QT/currPath");

    if (root.exists("Test")) {
        qInfo() << "Found 'Test'!";
        qInfo() << "Absolute Path: " << root.absoluteFilePath("Test");

        // Attempt to rename the folder to "Test2"
        if (root.rename("Test", "Test2")) {
            qInfo() << "Renamed 'Test' to 'Test2'";
            qInfo() << "New Absolute Path: " << root.absoluteFilePath("Test2");

            // Schedule removal of "Test2" after 5 seconds
            QTimer::singleShot(5000, [root]() mutable {
                if (root.rmdir("Test2")) {
                    qInfo() << "'Test2' folder is removed after delay!";
                } else {
                    qInfo() << "Failed to remove 'Test2' folder after delay!";
                }

                // Print the folder list again after removal
                QStringList folderList = root.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
                qInfo() << "Folders in currPath after removal:";
                foreach (QString folder, folderList) {
                    qInfo() << folder;
                }
            });
        } else {
            qInfo() << "Failed to rename 'Test' to 'Test2'";
        }
    } else {
        // Create "Test" folder if it does not exist
        qInfo() << "404! ";
        if (root.mkdir("Test")) {
            qInfo() << "'Test' folder is created!";
            qInfo() << "Absolute Path: " << root.absoluteFilePath("Test");
        } else {
            qInfo() << "Failed to create 'Test' folder!";
        }
    }

    // Show all folder names in currPath before removal
    QStringList folderList = root.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    qInfo() << "Folders in currPath before removal:";
    foreach (QString folder, folderList) {
        qInfo() << folder;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(QDir::currentPath());

    // Pass the QDir instance to modifyFile
    modifyFile(dir);


    // Retrieve specific information for a particular file
#if 0
    QString filePath = QDir::currentPath() + "/specificFile.txt";
    QFileInfo fileInfo(filePath);
    if (fileInfo.exists()) {
        qInfo() << "\nSpecific File Information:";
        qInfo() << "Absolute Path:" << fileInfo.absoluteFilePath();
    } else {
        qInfo() << "\nFile not found: " << filePath;
    }
#endif
    return a.exec();
}
