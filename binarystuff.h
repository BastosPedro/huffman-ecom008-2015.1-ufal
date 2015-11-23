#ifndef BINARYSTUFF_H
#define BINARYSTUFF_H
#include "QtCore"


class binaryStuff
{
public:
    static QByteArray bittheByte(QBitArray anyBits);
    static QBitArray bytetheBit(int pos, QByteArray anyByte);
    static QByteArray setHeaderString(QString anyArray);
    static int bitToString(QBitArray anyArray);
};

#endif // BINARYSTUFF_H
