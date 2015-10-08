#ifndef AUXILIA_H
#define AUXILIA_H

#include"tree.h"

class auxilia
{
public:
    static void printList(tree*& anyTree);
    static void printHash(tree*& anyTree);
    static void printRepresentation(tree*& anyTree);
    static void printFrequency(encode*& anyFile);
    static void printBitString(encode *&anyFile);
    static void printTree(node* anyNode, int level = 0);

    static void printAll(tree *anyTree, node *anyNode, encode *&anyFile);
};

#endif // AUXILIA_H
