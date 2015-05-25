#include <QDebug>
#include <QString>
//#include "read.h"
#include "list.h"
#include "tree.h"


int main() {
    QList <node*> mexico = list::read("/home/pedro/Documents/atahualpa.txt");
    tree* huffinho = new tree(mexico);
    QHash<uchar,QString> hash = huffinho->getHash();

    qDebug() << "\n\tShow Tree:\n";
    huffinho->printTree(huffinho->getRoot());
    qDebug()<< "Representando: " << qPrintable(huffinho->formalizing(huffinho->getRoot()));

}
