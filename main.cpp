#include <QApplication>
#include "printer.h"


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

    printer::printAll(invicta, invicta->getRoot(), roma);
    printer::printRepresentation(invicta);

    invicta->buildHeader(roma->getPath(), roma->getTrash());

    qDebug("temporis: %d ms", temporis.elapsed());
}
