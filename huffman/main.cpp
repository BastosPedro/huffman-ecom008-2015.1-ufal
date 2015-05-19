#include <QDebug>
#include <QString>
//#include "read.h"
#include "list.h"
#include "tree.h"


int main() {
    QList <node*> mexico = list::read("/home/pedro/Documents/atahualpa.txt");
    tree* huffinho = new tree(mexico);
    qDebug() << "\n\tShow Tree:\n";
    huffinho->printTree(huffinho->get());
    QHash<uchar,QString> hash = huffinho->getHash();

}
