#include "mainhub.h"

mainHub::mainHub(QObject *parent) : QObject(parent) {}

void mainHub::cCommand(QString path, QString out)
{
    qDebug() << "Beginning compression:" << endl;
    QTime temporis;
    temporis.start();

    fileinfo* roma = new fileinfo;
    roma->setPath(path);
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toVector(invicta->getRoot());
    invicta->representation(invicta->getRoot());

    roma->setBitString(invicta->getVector());
    qDebug() << "trash size:" << roma->getTrash();

    printer::printAll(invicta, invicta->getRoot(), roma);
    printer::printRepresentation(invicta);

    invicta->buildHeader(roma->getPath(), roma->getBitString(), roma->getTrash());
    roma->deliverPackageC(invicta->getHeader(), out);

    qDebug("\ntime: %d seconds", temporis.elapsed()/1000);
}

void mainHub::dCommand(QString path, QString dir)
{
    qDebug() << "We're still working here, please come back later.";
    QTime temporis;
    temporis.start();
    fileinfo* dalenda = new fileinfo;
    dalenda->setPath(path);
    dalenda->setReferences();
    dalenda->decodeHeader(dalenda->getBinaryFile());
    //tree* carthago;

}
