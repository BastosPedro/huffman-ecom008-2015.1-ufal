#include "compression.h"


int *compression::getFrequency() const
{
    return m_frequency;
}

int compression::getTrash() const
{
    return m_trash;
}

void compression::setPath(const QString &path)
{
    m_path += path;
}

void compression::setReferences()
{
    file = new QFile(m_path);
    Q_ASSERT_X(file->open(QIODevice::readOnly), Q_FUNC_INFO, "There is no file");
    binaryFile = file->readAll();
}

void compression::setBitString(QHash<uchar, QString> hash)
{
    for(int count = 0; count != binaryFile.size(); ++count) {
         bitString += hash.value(uchar(binaryFile.at(count)));
     }

     if(bitString.size() % 8) {
         m_trash = 8 - (bitString.size() % 8);
     }

     bitString.append("0").repeated(m_trash);
}
compression::compression()
{
    m_frequency = new int[256];
    for(int count = 0; count < 256; ++count) {
        m_frequency[count] = 0;
    }
    m_trash = 0;
    m_path = bitString = "";
}

compression::~compression()
{

}

int *compression::byteFrequency()
{
    setReferences();
    for (int count = 0; count != binaryFile.size(); ++count) {
        m_frequency[uchar(binaryFile.at(count))]++;
    }
}