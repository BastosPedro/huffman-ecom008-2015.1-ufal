#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <QByteArray>
#include <QFile>
#include <QIODevice>
#include <QString>
#include <QHash>


class compression
{
public:
    int* m_frequency, m_trash;
    QString m_path, bitString;
    QFile* m_file;
    QByteArray binaryFile;

    compression();
    ~compression();

    int* getFrequency() const;
    int getTrash() const;
    QString getBitString();

    void setPath(const QString &path);
    void setReferences();
    void setBitString(QHash<uchar, QString> hash);
    void byteFrequency();
};

#endif // COMPRESSION_H
