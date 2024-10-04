#include <QCoreApplication>
#include <QStorageInfo>
#include<QMap>
#include <QDebug>

void Display(const QStorageInfo &storage, const QString &title) {
    qInfo() << title;

    QMap<QString, QVariant> infoMap;
    infoMap["Name"] = storage.name();
    infoMap["Display Name"] = storage.displayName();
    infoMap["Root Path"] = storage.rootPath();
    infoMap["Device"] = storage.device();
    infoMap["File System Type"] = storage.fileSystemType();
    infoMap["Is Read-only"] = storage.isReadOnly() ? "Yes" : "No";
    infoMap["Is Ready"] = storage.isReady() ? "Yes" : "No";
    infoMap["Size (MB)"] = storage.bytesTotal() / (1024 * 1024);
    infoMap["Available Space (MB)"] = storage.bytesAvailable() / (1024 * 1024);
    infoMap["Free Space (MB)"] = storage.bytesFree() / (1024 * 1024);

    for (auto it = infoMap.constBegin(); it != infoMap.constEnd(); ++it) {
        qInfo() << it.key() << ": " << it.value().toString();
    }

    qInfo() << "";
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QList<QStorageInfo> storageList = QStorageInfo::mountedVolumes();

    for (const QStorageInfo &storage : storageList) {
        Display(storage, "Storage Info:");
    }

    return a.exec();
}
