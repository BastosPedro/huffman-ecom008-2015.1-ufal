#ifndef FILEINFO_H
#define FILEINFO_H

#include<QtCore>

class fileinfo
{
    int* m_frequency, m_trash;
    QString m_path, bitString;
    QFile* m_file;
    QByteArray binaryFile;
public:
    fileinfo();
    ~fileinfo();

    int* getFrequency() const;
    int getTrash() const;
    QString getBitString();

    void setPath(const QString &path);
    void setReferences();
    void setBitString(QVector<uchar> vector);
    void byteFrequency();
};

#endif // fileinfo_H
