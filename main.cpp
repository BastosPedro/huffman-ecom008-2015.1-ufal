#include <QApplication>
#include "auxilia.h"


int main() {

    QTime temporis;
    temporis.start();

    fileinfo* roma = new fileinfo;
    roma->setPath("/home/pedro/Documents/samples/standardascii.txt");
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toVector(invicta->getRoot());
    invicta->representation(invicta->getRoot());

    roma->setBitString(invicta->getVector());

    auxilia::printAll(invicta, invicta->getRoot(), roma);
    //auxilia::printTree(invicta->getRoot());
    //auxilia::printFrequency(roma);
    auxilia::printRepresentation(invicta);

    qDebug("temporis: %d ms", temporis.elapsed());
}
