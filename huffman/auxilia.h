#ifndef AUXILIA_H
#define AUXILIA_H

#include<QtAlgorithms>
#include<QDebug>
#include"tree.h"

class auxilia
{
public:
    static void printList(tree*& anyTree);
    static void printHash(tree*& anyTree);
    static void printRepresentation(tree*& anyTree);
    static void printFrequency(compression*& anyFile);
    static void printBitString(compression *&anyFile);
    static void printTree(node* anyNode, int level = 0);

    static void printAll(tree *anyTree, node *anyNode, compression *&anyFile);
};

#endif // AUXILIA_H
