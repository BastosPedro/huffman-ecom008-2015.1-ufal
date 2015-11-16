#include "binarystuff.h"

QByteArray binaryStuff::bittheByte(QBitArray anyBits)
{
    QByteArray auxBytes;
    auxBytes.resize(anyBits.count()/8+1);
    auxBytes.fill(0);
    for(int aux = 0; aux < (anyBits.count()); aux++){
        auxBytes[aux/8] = (auxBytes.at(aux/8) | ((anyBits[aux]?1:0) << (aux%8)));
    }
    //qDebug() << "result:" << auxBytes;
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

QByteArray binaryStuff::setHeaderString(QByteArray anyArray)
{
    QByteArray auxBytes;
    QBitArray auxBits(8);
    for(int countx = 0, county = 0; countx < anyArray.length(); countx++, county++){
        if(county == 7){
            county = 0;
            auxBytes += bittheByte(auxBits);
        }
        if(anyArray.at(countx) == '1'){
            auxBits.setBit(countx, true);
        }
        else{
            auxBits.setBit(county, false);
        }
    }
    //qDebug() << "ue, rodou wtf" << endl << auxBytes;
    return auxBytes;
}
