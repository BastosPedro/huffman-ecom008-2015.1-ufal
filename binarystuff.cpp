#include "binarystuff.h"

QByteArray binaryStuff::bittheByte(QBitArray anyBits)
{
    QByteArray auxBytes = 0;
    //int aux = anyBits.size();
    for(int count = 0; count < 7; count++){
        if(anyBits.at(7-count) == true){
            auxBytes += qPow(2, count);
        }
    }
    qDebug() << "result:" << auxBytes.toHex();
    return auxBytes;
}

QBitArray binaryStuff::bytetheBit(QByteArray anyByte)
{
    QBitArray auxBits;
    auxBits.resize(anyByte.count()*8);
    for(int countx = 0; countx < anyByte.count(); countx++){
        for(int county = 0; county < 8; county++){
            auxBits.setBit(countx*8+county, anyByte.at(countx) & (1<<(7-county)));
        }
    }
    //qDebug() << "result:" << auxBits;
    return auxBits;
}
QByteArray binaryStuff::appendQVector(QVector<uchar> anyVector){
    QByteArray auxBytes;
    int aux = anyVector.size();
    auxBytes.resize(aux);
    for(int count = 0; count < aux; count++){
        auxBytes[count] = anyVector[count];
    }
    return auxBytes;
}

QByteArray binaryStuff::setHeaderString(QString anyString)
{
    QByteArray auxBytes;
    /*QBitArray auxBits(8);
    int aux = anyString.length();
    //qDebug() << "whatever" << aux;
    for(int countx = 0, county = 0; countx < aux; countx++, county++){
        if(county == 7){
            county = 0;
            auxBytes += bittheByte(auxBits);
        }
        if(anyString.at(countx) == '1'){
            auxBits.setBit(county);
        }
        else{
            auxBits.clearBit(county);
        }
    }*/
    while(anyString.length()){
        QString byte = anyString.left(8);
        anyString.remove(0, 8);
        //std::reverse(byte.begin(), byte.end());
        char aux = byte.toInt(0, 2);
        auxBytes.append(aux);
    }
    //std::reverse(auxBytes.begin(), auxBytes.end());
    //qDebug() << "result:" << auxBytes;
    return auxBytes;
}
