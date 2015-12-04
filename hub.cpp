#include "hub.h"

hub::hub(QObject *parent) : QObject(parent)
{

}

void hub::cCommand(QString path, QString out)
{
    std::cout << "Beginning compression:\n";
    QTime temporis;
    temporis.start();;

    fileinfo* roma = new fileinfo;
    roma->setPath(path);
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toVector(invicta->getRoot());
    roma->setBitString(invicta->getVector());
    invicta->representation(invicta->getRoot());

    printer::printAll(invicta, invicta->getRoot(), roma);
    printer::printRepresentation(invicta);

    invicta->buildHeader(roma->getPath(), roma->getBitString(), roma->getTrash());
    roma->deliverPackageC(invicta->getHeader(), out);

    std::cout << "Complete:" << temporis.elapsed()/1000 << " seconds\n";
}

void hub::dCommand(QString path, QString dir)
{
    if(path.contains(".huff")){
        std::cout << "Beginning decompression:\n";

        QTime temporis;
        temporis.start();

        if(dir == ""){
            dir = QFileInfo(path).absolutePath();
        }
        fileinfo* dalenda = new fileinfo;
        dalenda->setPath(path);
        dalenda->decodeHeader(path, dir);
        tree* carthago = new tree(dalenda->getRepTree());
        carthago->decodeTheCode(dalenda->getBitsFile());
        dalenda->deliverPackageD(carthago->getDecoded());

        std::cout << "Complete:" << temporis.elapsed()/1000 << " seconds";
    }
    else{
        std::cout << "Wrong file, please insert a .huff one.";
    }
}

