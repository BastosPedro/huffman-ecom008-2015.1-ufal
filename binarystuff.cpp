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
    //qDebug() << "result:" << auxBytes.toHex();
    return auxBytes;
}

QVector<bool> binaryStuff::bytetheBit(quint8 anyByte)
{
    QVector<bool> auxBits(8);
    auxBits[0] = anyByte&1<<7;
    auxBits[1] = anyByte&1<<6;
    auxBits[2] = anyByte&1<<5;
    auxBits[3] = anyByte&1<<4;
    auxBits[4] = anyByte&1<<3;
    auxBits[5] = anyByte&1<<2;
    auxBits[6] = anyByte&1<<1;
    auxBits[7] = anyByte&1;
    /*QVector<bool> auxBits;
    for(int countx = 0; countx < pos; countx++){
        for(int county = 0; county < 8; county++){
            auxBits += (anyByte.at(countx) & (0x1 << (7-county)));
        }
    }*/
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
    /*while(anyString.length()){
        QString aux = anyString.left(8);
        anyString.remove(0, 8);
        char auxY = aux.toInt(0,2);
        auxBytes.append(auxY);
    }*/
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
