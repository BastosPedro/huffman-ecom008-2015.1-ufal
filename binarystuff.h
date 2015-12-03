#ifndef BINARYSTUFF_H
#define BINARYSTUFF_H
#include "QtCore"


class binaryStuff
{
public:
    static QByteArray bittheByte(QBitArray anyBits);
    static QVector<bool> bytetheBit(quint8 anyByte);
    static QByteArray setHeaderString(QString anyArray);
    static int bitToInt(QBitArray anyArray);
};

#endif // BINARYSTUFF_H
