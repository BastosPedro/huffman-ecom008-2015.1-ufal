#include "binarystuff.h"

QByteArray binaryStuff::bittheByte(QBitArray anyBits)
{
    QByteArray auxBytes;
    auxBytes.resize(anyBits.count()/8+1);
    auxBytes.fill(0);
    for(int aux = 0; aux < (anyBits.count()); aux++){
        auxBytes[aux/8] = (auxBytes.at(aux/8) | ((anyBits[aux]?1:0) << (7 -(aux%8))));
    }
    return auxBytes;
}

QBitArray binaryStuff::bytetheBit(QByteArray anyByte)
{
    QBitArray auxBits(anyByte.count()*8);
    auxBits.resize(anyByte.count()*8);
    for(int countx = 0; countx < (anyByte.count()); countx++){
        for(int county = 0; county < 8; county++){
            auxBits.setBit(countx*8+county, anyByte.at(countx)&(1<<(7-county)));
        }
    }
    //qDebug << "result:" << auxBits;
    return auxBits;
}

QByteArray binaryStuff::setBinaryString(QString anyString)
{
    QByteArray auxBytes;
    QBitArray auxBits(8);
    for(int countx = 0, county = 0; countx < anyString.length(); countx++, county++){
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
