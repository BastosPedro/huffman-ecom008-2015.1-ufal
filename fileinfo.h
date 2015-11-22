#ifndef FILEINFO_H
#define FILEINFO_H

#include<QtCore>

class fileinfo
{
    int* m_frequency, m_trash;
    QString m_path, path_out;
    QFile* m_file;
    QByteArray binaryFile, bitString;
public:

    fileinfo();
    ~fileinfo();

    int* getFrequency() const;
    int getTrash() const;
    QByteArray getBitString();

    void setPath(const QString &path);
    void setReferences();
    void setBitString(QVector<QString> vector);
    void byteFrequency();
    void deliverPackageC(QByteArray anyHeader, QString out);
    QString getPath() const;
};

#endif // fileinfo_H
