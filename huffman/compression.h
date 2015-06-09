#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <QByteArray>
#include <QFile>
#include <QIODevice>
#include <QString>


class compression
{
public:
    int* m_frequency, m_trash;
    QString m_path, bitString;
    QFile* archive;
    QByteArray binaryFile;

    compression();
    ~compression();

    int* getFrequency() const;
    int getTrash() const;
    QString getBitString(QHash<uchar, QString> hash);

    void setPath(const QString &path);
    void setReferences();
    void setBitString(QHash<uchar, QString> hash);
    void byteFrequency(QString Directory);
};

#endif // COMPRESSION_H
