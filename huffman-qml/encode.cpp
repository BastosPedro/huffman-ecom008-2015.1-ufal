#include "encode.h"


int *encode::getFrequency() const
{
    return m_frequency;
}

int encode::getTrash() const
{
    return m_trash;
}

QString encode::getBitString()
{
    return bitString;
}

void encode::setPath(const QString &path)
{
    m_path += path;
}

void encode::setReferences()
{
    m_file = new QFile(m_path);
    Q_ASSERT_X(m_file->open(QIODevice::ReadOnly), Q_FUNC_INFO, "There is no file");
    binaryFile = m_file->read(1024);
}

void encode::setBitString(QHash<uchar, QString> hash)
{
    for(int count = 0; count != binaryFile.size(); count++) {
         bitString += hash.value(uchar(binaryFile.at(count)));
     }

     if(bitString.size() % 8) {
         m_trash = 8 - (bitString.size() % 8);
     }

     bitString.append("0").repeated(m_trash);
}

void encode::byteFrequency()
{
    setReferences();
    for (int count = 0; count != binaryFile.size(); count++) {
        m_frequency[uchar(binaryFile.at(count))]++;
    }
}

encode::encode()
{
    m_frequency = new int[256];
    for(int count = 0; count < 256; count++) {
        m_frequency[count] = 0;
    }
    m_trash = 0;
    m_path = bitString = "";
}

encode::~encode()
{

}
