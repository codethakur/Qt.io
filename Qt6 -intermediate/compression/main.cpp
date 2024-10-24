#include <QCoreApplication>
#include <QFile>
#include <QByteArray>
#include <QDebug>

// Function to create a file and populate it with some sample data
bool makeFile(QString path)
{
    QFile file(path);
    QByteArray data;

    if (file.open(QIODevice::WriteOnly))
    {
        for (int i = 0; i < 100; i++)
        {
            if (i % 2 == 0)
            {
                data.append(QString::number(i).toUtf8() + " ");
            }
        }
        file.write(data);
        file.close();
        return true;
    }
    return false;
}

// Function to generate a custom header used during compression
QByteArray getHeader()
{
    QByteArray header;
    header.append("!@!@#$%^"); // Define your custom header
    return header;
}

// Function to compress a file
bool Compressing(QString originalFile, QString newFile)
{
    QFile orgFile(originalFile);
    QFile compFile(newFile);
    int size = 1024;  // Buffer size
    QByteArray header = getHeader();

    if (!orgFile.open(QIODevice::ReadOnly)) return false;
    if (!compFile.open(QIODevice::WriteOnly)) return false;

    // Read and compress the original file in chunks
    while (!orgFile.atEnd())
    {
        QByteArray buffer = orgFile.read(size);  // Read 1024 bytes
        QByteArray compressed = qCompress(buffer, 9);  // Compress the chunk
        compFile.write(header);  // Write the custom header before each compressed block
        compFile.write(compressed);  // Write the compressed data
    }

    orgFile.close();
    compFile.close();
    qInfo() << "Compressed successfully!";
    return true;
}

// Function to decompress a file
bool Decompressing(QString compressedFile, QString newFile)
{
    QFile orgFile(compressedFile);
    QFile decompFile(newFile);
    int size = 1024;  // Buffer size
    QByteArray header = getHeader();

    if (!orgFile.open(QIODevice::ReadOnly)) return false;
    if (!decompFile.open(QIODevice::WriteOnly)) return false;

    // Verify the first header exists
    QByteArray buffer = orgFile.read(header.size());
    if (!buffer.startsWith(header))
    {
        qWarning() << "Header not found in file!";
        orgFile.close();
        decompFile.close();
        return false;
    }

    // Read and decompress data block by block
    while (!orgFile.atEnd())
    {
        buffer = orgFile.read(size);
        qint64 index = buffer.indexOf(header);  // Find the next header

        if (index > -1)  // If the header is found
        {
            QByteArray compressedData = buffer.left(index);  // Get data before the header
            QByteArray decompressed = qUncompress(compressedData);  // Decompress
            decompFile.write(decompressed);  // Write decompressed data

            // Move the file pointer past the header for the next block
            orgFile.seek(orgFile.pos() - (buffer.size() - index) + header.size());
        }
        else
        {
            QByteArray decompressed = qUncompress(buffer);  // Decompress the remaining data
            decompFile.write(decompressed);  // Write it to the new file
        }
    }

    orgFile.close();
    decompFile.close();
    qInfo() << "Decompressed successfully!";
    return true;
}

// Main function
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString original("A:/Qt6/FileCompresing/makeFile.txt");
    QString compressedFile("A:/Qt6/FileCompresing/FileCompress.txt");
    QString decompressedFile("A:/Qt6/FileCompresing/FileDecompress.txt");

    // Create the original file
    if (makeFile(original))
    {
        qInfo() << "File has been created successfully!";

        // Compress the original file
        if (Compressing(original, compressedFile))
        {
            qInfo() << "File compressed!";

            // Decompress the file
            if (Decompressing(compressedFile, decompressedFile))
            {
                qInfo() << "File decompressed!";
            }
            else
            {
                qInfo() << "Decompression failed!";
            }
        }
        else
        {
            qWarning() << "Compression failed!";
        }
    }

    return a.exec();
}
