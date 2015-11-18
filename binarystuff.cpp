#include "binarystuff.h"

QByteArray binaryStuff::bittheByte(QBitArray &anyBits)
{
    QByteArray auxBytes(anyBits.count()/8, '0');
    int aux = anyBits.count();
    for(int countx = 0; countx < aux; countx++){
        auxBytes[(countx/8)] = (auxBytes.at(countx/8) | ((anyBits.at(countx)?1:0) << (7 - (countx%8))));
    }
    qDebug() << "result:" << auxBytes.toHex();
    qDebug() << "sei la:" << aux;
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
            auxBits.setBit(countx, true);
        }
        else{
            auxBits.setBit(county, false);
        }
    }
    return auxBytes;
}
