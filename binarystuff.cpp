#include "binarystuff.h"

QByteArray binaryStuff::bittheByte(QBitArray anyBits)
{
    int aux = anyBits.count();
    QByteArray auxBytes;
    auxBytes.resize(aux/8);
    auxBytes.fill(0);
    for(int count = 0; count < aux; count++){
        auxBytes[count/8] = (auxBytes.at(count/8)) | ((anyBits[count] ? 1:0)<<(7 - (count%8)));
    }
    qDebug() << "result:" << auxBytes.toHex();
    return auxBytes;
}

QVector<bool> binaryStuff::bytetheBit(int pos, QByteArray anyByte)
{
    QVector<bool> auxBits;
    for(int countx = 0; countx < pos; countx++){
        for(int county = 0; county < 8; county++){
            auxBits += (anyByte.at(countx) & (0x1 << (7-county)));
        }
    }
    return auxBits;
}

QByteArray binaryStuff::setHeaderString(QString anyString)
{
    QByteArray auxBytes;
    QBitArray auxBits(8);
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
            auxBits.setBit(county, 0);
        }
    }
    return auxBytes;
}

int binaryStuff::bitToInt(QBitArray anyArray)
{
    int aux = anyArray.size();
    int result = 0;
    for(int countx = 0, county = aux - 1; countx < aux; countx++, county--){
        result += anyArray.at(countx) * qPow(2, county);
    }
    return result;
}
