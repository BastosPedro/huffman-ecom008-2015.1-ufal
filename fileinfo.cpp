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

void fileinfo::decodeHeader(QString path)
{
    std::cout << "beginning decoding";
    m_path = path;
    //path_out = out;
    quint16 auxBytes = 0;
    m_file = new QFile(m_path);
    Q_ASSERT_X(m_file->open(QIODevice::ReadOnly), Q_FUNC_INFO, "There is no file");
    //if(m_file->open(QIODevice::ReadOnly)){
    QDataStream auxStream(m_file);
    auxStream >> auxBytes;
    quint8 auxTrash = 0;
    if(auxBytes & (1<<13)){
        auxTrash+= 1;
    }
    if(auxBytes & (1<<14)){
        auxTrash+= 2;
    }
    if(auxBytes & (1<<15)){
        auxTrash+= 4;
    }
    auxBytes ^= (-0 ^ auxBytes) & (1<<13);
    auxBytes ^= (-0 ^ auxBytes) & (1<<14);
    auxBytes ^= (-0 ^ auxBytes) & (1<<15);

    quint8 auxNSize;
    auxStream >> auxNSize;
    m_file->seek(3);
    QString auxFName;
    auxFName.resize(auxNSize);
    auxFName = m_file->read(auxNSize);
    m_file->seek(auxNSize + 3);
    QByteArray auxRep;
    auxRep.resize(auxBytes);
    auxRep = m_file->read(auxBytes);

    m_trash = auxTrash;
    qDebug() << "trash size:" << m_trash;
    sizeTree = auxBytes;
    qDebug() << "tree size:" << sizeTree;
    sizeName = auxNSize;
    qDebug() << "name size:" << sizeName;
    fileName = auxFName;
    qDebug() << "file name:" << fileName;
    repTree = auxRep;
    qDebug() << "representation" << repTree;
    bool flag = m_file->seek(3 + sizeTree + sizeName);
    if(flag) binaryFile = m_file->readAll();
    else qDebug() << "a problem has occurred";
    m_file->close();
}


// Getters, Setters, etc //
void fileinfo::setReferences()
{
    m_file = new QFile(m_path);
    Q_ASSERT_X(m_file->open(QIODevice::ReadOnly), Q_FUNC_INFO, "There is no file");
    while(!m_file->atEnd()){
        binaryFile += m_file->read(8000000);
    }
    m_file->close();
}

void fileinfo::setBitString(QVector<QString> vector)
{
    int aux = binaryFile.size();
    for(int count = 0; count < aux; count++) {
         bitString += vector.value(binaryFile.at(count));

    }
    //qDebug() << "binaryfile: " << binaryFile;
    if(bitString.size() % 8) {
         m_trash = (8 - (bitString.size() % 8));
         qDebug() << "first trash size I guess:" << m_trash;
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
QString fileinfo::getFileName() const
{
    return fileName;
}
