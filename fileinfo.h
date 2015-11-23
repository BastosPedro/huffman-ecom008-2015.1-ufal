#ifndef FILEINFO_H
#define FILEINFO_H

#include"binarystuff.h"

class fileinfo
{
    int* m_frequency, m_trash,
         sizeTree, sizeName;
    QString m_path, path_out, fileName;
    QFile* m_file;
    QByteArray binaryFile, bitString, repTree;
    QBitArray codification;
public:

    fileinfo();
    ~fileinfo();

    int* getFrequency() const;
    int getTrash() const;
    QByteArray getBitString();
    QByteArray getBinaryFile();
    QByteArray getRepTree() const;
    QString getPath() const;

    void setPath(const QString &path);
    void setReferences();
    void setBitString(QVector<QString> vector);
    void byteFrequency();
    void deliverPackageC(QByteArray anyHeader, QString out);
    void deliverPackageD(QByteArray counterHeader, QString out);

//the methods below are exclusive to the decompression
    void getBin(QByteArray anyFile);
    void decodeHeader();
    QBitArray getCodification() const;
    QString getFileName() const;
};

#endif // fileinfo_H
