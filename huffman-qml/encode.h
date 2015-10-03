#ifndef ENCODE_H
#define ENCODE_H

#include<QtCore>

class encode
{
public:
    int* m_frequency, m_trash;
    QString m_path, bitString;
    QFile* m_file;
    QByteArray binaryFile;

    encode();
    ~encode();

    int* getFrequency() const;
    int getTrash() const;
    QString getBitString();

    void setPath(const QString &path);
    void setReferences();
    void setBitString(QHash<uchar, QString> hash);
    void byteFrequency();
};

#endif // encode_H
