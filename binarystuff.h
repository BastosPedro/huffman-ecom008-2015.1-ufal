#ifndef BINARYSTUFF_H
#define BINARYSTUFF_H
#include "fileinfo.h"


class binaryStuff
{
public:
    static QByteArray bittheByte(QBitArray anyBits);
    static QBitArray bytetheBit(QByteArray anyByte);
    static QByteArray setHeaderString(QString anyArray);
    static QByteArray appendQVector(QVector<uchar>);
};

#endif // BINARYSTUFF_H
