#include "fileinfo.h"

fileinfo::fileinfo()
{
    m_frequency = new int[256];
    for(int count = 0; count < 256; count++) {
        m_frequency[count] = 0;
    }
    m_trash = 0;
    m_path = bitString = "";
}

fileinfo::~fileinfo()
{

}

void fileinfo::byteFrequency()
{
    setReferences();
    for (int count = 0; count != binaryFile.size(); count++) {
        m_frequency[uchar(binaryFile.at(count))]++;
    }
}

// Getters, Setters, etc //
void fileinfo::setReferences()
{
    m_file = new QFile(m_path);
    Q_ASSERT_X(m_file->open(QIODevice::ReadOnly), Q_FUNC_INFO, "There is no file");
    binaryFile = m_file->read(1024);
}

void fileinfo::setBitString(QVector<uchar> vector)
{
    for(int count = 0; count != binaryFile.size(); count++) {
         bitString += vector.value(uchar(binaryFile.at(count)));
     }

     if(bitString.size() % 8) {
         m_trash = 8 - (bitString.size() % 8);
     }
     bitString.append("0").repeated(m_trash);
}

void fileinfo::setPath(const QString &path)
{
    m_path += path;
}

int *fileinfo::getFrequency() const
{
    return m_frequency;
}

int fileinfo::getTrash() const
{
    return m_trash;
}

QString fileinfo::getBitString()
{
    return bitString;
}
