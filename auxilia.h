#ifndef AUXILIA_H
#define AUXILIA_H

#include"tree.h"

class auxilia
{
public:
    static void printList(tree*& anyTree);
    static void printHash(tree*& anyTree);
    static void printRepresentation(tree*& anyTree);
    static void printFrequency(fileinfo*& anyFile);
    static void printBitString(fileinfo *&anyFile);
    static void printTree(node* anyNode, int level = 0);

    static void printAll(tree *anyTree, node *anyNode, fileinfo *&anyFile);
};

#endif // AUXILIA_H
