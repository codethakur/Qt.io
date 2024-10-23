#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello from Qt";
    QByteArray encoding = data.toLatin1().toBase64();
    QByteArray decoding = QByteArray::fromBase64(encoding);
    QByteArray B_encoding = QByteArray(reinterpret_cast<const char*>(data.utf16()), data.length() * 2).toBase64(); // UTF-16 encoding
    QByteArray decoding_B = QByteArray::fromBase64(encoding); // Decoding needs to be handled correctly

    qInfo() << "UTF-16 Base64 encoding: " << encoding;

    qInfo() << "encoding: " << encoding;
    qInfo() << "-----------\n";
    qInfo() << "decoding: " << decoding;
    qInfo() << "-----------\n";
    qInfo() << "B_encoding: " << B_encoding;
    qInfo() << "-----------\n";
    qInfo() << "decoding_B: " << decoding_B;

    // Corrected file path with forward slashes
    QFile file("A:/Qt6/encodings-Assignment/encoDecode.txt");

    if (file.open(QIODevice::WriteOnly)) {
        // Write encoded and decoded data to the file
        file.write("Encoded: " + encoding + "\n");
        file.write("Decoded: " + decoding + "\n");
        file.write("B_encoding: " +B_encoding + "\n");
        file.write("decoding_B: " + decoding_B + "\n");

        file.close();
        qInfo() << "File written successfully.";
    } else {
        qInfo() << "Failed to open the file for writing!";
    }

    return a.exec();
}
