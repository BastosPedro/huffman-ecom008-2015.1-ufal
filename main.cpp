#include <QApplication>
#include "printer.h"


int main() {

    QTime temporis;
    temporis.start();

    fileinfo* roma = new fileinfo;
    roma->setPath("/home/pedro/Documents/samples/guilin_china.bmp");
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toVector(invicta->getRoot());
    invicta->representation(invicta->getRoot());

    roma->setBitString(invicta->getVector());
    //Debug() << "tamanho do lixo:" << roma->getTrash();

    printer::printAll(invicta, invicta->getRoot(), roma);
    printer::printRepresentation(invicta);

    invicta->buildHeader(roma->getPath(), roma->getBitString(), roma->getTrash());
    roma->deliverPackage(invicta->getHeader());
    qDebug("\ntemporis: %d segundos", temporis.elapsed()/1000);
}
