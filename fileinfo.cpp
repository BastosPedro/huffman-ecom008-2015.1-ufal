#include "fileinfo.h"

QString fileinfo::getPath() const
{
    return m_path;
}

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
    int size = binaryFile.size();
    for (int count = 0; count != size; count++) {
        m_frequency[uchar(binaryFile.at(count))]++;
    }
}

void fileinfo::deliverPackage(QByteArray anyHeader){
    QString auxPath = m_path;
    auxPath.chop(auxPath.size() - auxPath.lastIndexOf('.'));
    auxPath.append(".huff");
    qDebug()<< "caminho de volta:" << auxPath;
    QFile finalFile(auxPath);
    finalFile.open(QIODevice::WriteOnly);
    finalFile.write(anyHeader);
    finalFile.close();

}

// Getters, Setters, etc //
void fileinfo::setReferences()
{
    m_file = new QFile(m_path);
    Q_ASSERT_X(m_file->open(QIODevice::ReadOnly), Q_FUNC_INFO, "There is no file");
    while(!m_file->atEnd()){
        binaryFile += m_file->read(8000000);
    }
}

void fileinfo::setBitString(QVector<QString> vector)
{
    int aux = binaryFile.size();
    for(int count = 0; count < aux; count++) {
         bitString += vector.value(binaryFile.at(count));

    }
    //qDebug() << "binaryfile: " << binaryFile;
    if(bitString.size() % 8) {
         m_trash = 8 - (bitString.size() % 8);
    }
    //bitString += (QString('0').repeated(m_trash));
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

QByteArray fileinfo::getBitString()
{
    return bitString;
}
