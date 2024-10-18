#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

void info(QSettings &settings)
{
    qInfo() << "File: " << settings.fileName();
    qInfo() << "Keys: " << settings.allKeys();
}

void save(QSettings &settings)
{
    // Example of saving settings under a group
    settings.beginGroup("Window");
    settings.setValue("width", 800);
    settings.setValue("height", 600);
    settings.endGroup();

    settings.beginGroup("User");
    settings.setValue("username", "johnDoe");
    settings.setValue("email", "john@example.com");
    settings.endGroup();

    qInfo() << "Settings saved!";
    settings.sync();  // Force writing to disk
}

void load(QSettings &settings)
{
    qInfo() << settings.value("loading").toString();
    bool ok;
    qInfo() << settings.value("loading").toInt(&ok);
    if (!ok) {
        qInfo() << "Could not convert\n";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Micro");
    QCoreApplication::setOrganizationDomain("microDev.com");
    QCoreApplication::setApplicationName("Dev");

    // Use the specific file path
    //QString filePath = "C:/Users/YourUsername/Documents/mySettings.ini";  // You can customize this path

    // Use QSettings to save to a specific file
    QSettings settings(filePath, QSettings::IniFormat);

    save(settings);
    qInfo() << "----------\n";
    info(settings);
    qInfo() << "----------\n";
    load(settings);

    return a.exec();
}
