#include "auxilia.h"



void auxilia::printList(tree *&anyTree)
{
    qDebug() << endl << endl;
    for(int count = 0; count < anyTree->getList().size(); count++){
        qDebug() << "Symbol:\t" << anyTree->getList().at(count)->getSymbol() << "\t"
                    "Repetitions:\t" << anyTree->getList().at(count)->getRepetition();
    }
    qDebug() << endl << endl;
}

void auxilia::printHash(tree *&anyTree)
{
    //QVector<uchar>::const_iterator count;
    qDebug() << endl << endl;
    for(int count = 0;
        count < anyTree->getVector().length(); count++) {
        qDebug() << ": " << qPrintable(anyTree->getVector().at(count)) << endl;
    }
}

void auxilia::printRepresentation(tree *&anyTree)
{
    qDebug() << endl << "Representing the tree: " << endl
             << qPrintable(anyTree->getRepresentation());
}

void auxilia::printFrequency(fileinfo *&anyFile)
{
    qDebug() << endl << endl;
    for(int count = 0 ; count < 256 ; count++) {
        if(anyFile->getFrequency()[count]) {
            qDebug() << qPrintable(QString(count)) << "\t"
                     << "ASCII:\t" << count << "\t"
                     << "Symbol:\t" <<char(count) << "\t"
                     << "Repetitions:\t" << anyFile->getFrequency()[count];
        }
    }
}

void auxilia::printBitString(fileinfo *&anyFile)
{
    qDebug() << endl << endl << "This is the codification in bits: " << endl << anyFile->getBitString();
}

void auxilia::printTree(node *anyNode, int level)
{
    if(anyNode != 0) {
        printTree(anyNode->getRightchild(), level + 1);
        if(anyNode->isLeaf()){
                qDebug() << qPrintable(QString("\t").repeated(level))
                         << char(anyNode->getSymbol()) << "/"
                         << anyNode->getRepetition();
        }
        else{
           qDebug() << qPrintable(QString("\t").repeated(level)) << char(46);
           printTree(anyNode->getLeftchild(), level + 1);
       }
    }
}

void auxilia::printAll(tree* anyTree, node* anyNode, fileinfo*& anyFile)
{
    printList(anyTree);
    printHash(anyTree);
    printRepresentation(anyTree);
    printFrequency(anyFile);
    printTree(anyNode);
}
