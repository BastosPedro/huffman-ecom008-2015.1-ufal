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

    qDebug() << "Beginning decompression:" << endl;

    QTime temporis;
    temporis.start();

    if(dir == ""){
        dir = QFileInfo(path).absolutePath();
    }
    fileinfo* dalenda = new fileinfo;
    dalenda->setPath(path);
    dalenda->decodeHeader();
    tree* carthago = new tree;
    carthago->rebuildTree(dalenda->getRepTree());
    //sQByteArray fileRes = tree::counterHeader(dalenda->getCodification(), tree::getRoot());
    dalenda->deliverPackageD(carthago->counterHeader(dalenda->getCodification(), carthago->getRoot()),
                             dir + "/" + dalenda->getFileName());

    qDebug("\ntime: %d seconds", temporis.elapsed()/1000);

}
