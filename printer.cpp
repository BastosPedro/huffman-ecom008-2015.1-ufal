#include "printer.h"



void printer::printList(tree *&anyTree)
{
    qDebug() << endl << endl;
    for(int count = 0; count < anyTree->getList().size(); count++){
        qDebug() << "Symbol:\t" << anyTree->getList().at(count)->getSymbol() << "\t"
                    "Repetitions:\t" << anyTree->getList().at(count)->getRepetition();
    }
    qDebug() << endl << endl;
}

void printer::printVector(tree *&anyTree)
{
    qDebug() << endl << endl;
    for(int count = 0; count < anyTree->getVector().length(); count++) {
        qDebug() << ": " << qPrintable(anyTree->getVector().at(count)) << endl;
    }
}

void printer::printRepresentation(tree *&anyTree)
{
    qDebug() << endl << "Representing the tree: " << endl
             << qPrintable(anyTree->getRepresentation());
}

void printer::printFrequency(fileinfo *&anyFile)
{
    qDebug() << endl << endl;
    for(int count = 0 ; count < 256 ; count++) {
        if(anyFile->getFrequency()[count]) {
            qDebug() << qPrintable(QString(count)) << "\t"
                     << "ASCII:\t" << count << "\t"
                     << "Symbol:\t" << char(count) << "\t"
                     << "Repetitions:\t" << anyFile->getFrequency()[count];
        }
    }
}

void printer::printBitString(fileinfo *&anyFile)
{
    qDebug() << endl << endl << "This is the codification in bits: " << endl << anyFile->getBitString();
}

void printer::printTree(node *anyNode, int level)
{
    if(anyNode != 0) {
        printTree(anyNode->getRightchild(), level + 1);
        if(anyNode->isLeaf()){
                qDebug() << qPrintable(QString("\t").repeated(level))
                         << uchar(anyNode->getSymbol()) << "/" << anyNode->getRepetition();
        }
        else{
           qDebug() << qPrintable(QString("\t").repeated(level)) << char(46);
        }
        printTree(anyNode->getLeftchild(), level + 1);
    }
}

void printer::printAll(tree* anyTree, node* anyNode, fileinfo*& anyFile)
{
    printList(anyTree);
    printVector(anyTree);
    printRepresentation(anyTree);
    printFrequency(anyFile);
    printTree(anyNode);
}
