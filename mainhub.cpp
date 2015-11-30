#include "mainhub.h"

mainHub::mainHub(QObject *parent) : QObject(parent) {}

void mainHub::cCommand(QString path, QString out)
{
    std::cout << "Beginning compression:\n";
    QTime temporis;
    temporis.start();

    fileinfo* roma = new fileinfo;
    roma->setPath(path);
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toVector(invicta->getRoot());
    invicta->representation(invicta->getRoot());

    roma->setBitString(invicta->getVector());
    std::cout << "trash size:" << roma->getTrash() << "\n";

    printer::printAll(invicta, invicta->getRoot(), roma);
    printer::printRepresentation(invicta);

    invicta->buildHeader(roma->getPath(), roma->getBitString(), roma->getTrash());
    roma->deliverPackageC(invicta->getHeader(), out);

    std::cout << "Complete:" << temporis.elapsed()/1000 << " seconds\n";
}

void mainHub::dCommand(QString path, QString dir)
{

    std::cout << "Beginning decompression:" << endl;

    QTime temporis;
    temporis.start();

    if(dir == ""){
        dir = QFileInfo(path).absolutePath();
    }
    fileinfo* dalenda = new fileinfo;
    dalenda->setPath(path);
    dalenda->decodeHeader(path);
    tree* carthago = new tree;
    carthago->rebuildTree(dalenda->getRepTree());
    carthago->decodeTheCode(dalenda->getBinaryFile(), dalenda->getTrash());
    //dalenda->deliverPackageD();

    std::cout << "Complete:" << temporis.elapsed()/1000 << " seconds";

}
