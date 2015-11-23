#include "fileinfo.h"

fileinfo::fileinfo()
{
    m_trash = 0;
    m_path = bitString = "";
}

fileinfo::~fileinfo()
{

}

void fileinfo::byteFrequency()
{
    setReferences();
    m_frequency = new int[256];
    for(int count = 0; count < 256; count++) {
        m_frequency[count] = 0;
    }
    int size = binaryFile.size();
    for (int count = 0; count != size; count++) {
        m_frequency[uchar(binaryFile.at(count))]++;
    }
}

void fileinfo::deliverPackageC(QByteArray anyHeader, QString out){
    if(out == ""){
         path_out = m_path;
         path_out.chop(path_out.size() - path_out.lastIndexOf('.'));
         path_out.append(".huff");
    }
    else path_out = out;
    qDebug()<< "caminho de volta:" << path_out;
    QFile finalFile(path_out);
    finalFile.open(QIODevice::WriteOnly);
    finalFile.write(anyHeader);
    finalFile.close();

}

void fileinfo::deliverPackageD(QByteArray counterHeader, QString out)
{
    QFile finalFile(out);
    finalFile.open(QIODevice::WriteOnly);
    finalFile.write(counterHeader);
    finalFile.close();
}

void fileinfo::getBin(QByteArray anyFile)
{
    QBitArray aux1 = binaryStuff::bytetheBit(anyFile.size(), anyFile);
    QBitArray bitTrash(3);
    bitTrash.setBit(0, aux1.at(0));
    bitTrash.setBit(1, aux1.at(1));
    bitTrash.setBit(2, aux1.at(2));
    for(int count = 0; count < 3; count++){
        aux1.clearBit(count);
    }
    QBitArray aux2 = binaryStuff::bytetheBit(anyFile.size(), anyFile);
    aux1.resize(16);
    for(int count = 0; count < 16; count++){
        aux1.setBit(count, aux2.at(count - 8));
    }
    m_trash = binaryStuff::bitToString(bitTrash);
    sizeTree = binaryStuff::bitToString(aux1);


}

void fileinfo::decodeHeader()
{
    setReferences();
    getBin(binaryFile.left(2));
    sizeName = binaryFile.at(2);
    binaryFile.remove(0,3);
    fileName = binaryFile.left(sizeName);
    binaryFile.remove(0, sizeName);
    repTree = binaryFile.left(sizeTree);
    binaryFile.remove(0, sizeTree);
    codification.resize(binaryFile.size()*8 - m_trash);
    codification.fill(0);
    //int aux = codification.size();
    codification = binaryStuff::bytetheBit(binaryFile.size(), binaryFile);
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
QString fileinfo::getPath() const
{
    return m_path;
}
QByteArray fileinfo::getBinaryFile()
{
    return binaryFile;
}
QByteArray fileinfo::getRepTree() const
{
    return repTree;
}

QBitArray fileinfo::getCodification() const
{
    return codification;
}

QString fileinfo::getFileName() const
{
    return fileName;
}
