#ifndef LIST_H
#define LIST_H
#include <QList>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QByteArray>
#include <QtAlgorithms>
#include <QDebug>
#include "node.h"

class list
{
public:
    static QList<node*> toQList(int * array);
    static QList<node*> read(QString path);
    void print(int* text);
};

#endif // LIST_H
