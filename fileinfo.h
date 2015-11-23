#ifndef FILEINFO_H
#define FILEINFO_H

#include"binarystuff.h"

class fileinfo
{
    int* m_frequency, m_trash, sizeTree;
    QString m_path, path_out;
    QFile* m_file;
    QByteArray binaryFile, bitString;
public:

    fileinfo();
    ~fileinfo();

    int* getFrequency() const;
    int getTrash() const;
    QByteArray getBitString();
    QByteArray getBinaryFile();
    QString getPath() const;

    void setPath(const QString &path);
    void setReferences();
    void setBitString(QVector<QString> vector);
    void byteFrequency();
    void deliverPackageC(QByteArray anyHeader, QString out);

//the methods below are exclusive to the decompression
    void decodeHeader(QByteArray anyFile);
};

#endif // fileinfo_H
