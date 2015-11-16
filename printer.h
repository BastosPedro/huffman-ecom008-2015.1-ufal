#ifndef PRINTER_H
#define PRINTER_H

#include"tree.h"

class printer
{
public:
    static void printList(tree*& anyTree);
    static void printVector(tree*& anyTree);
    static void printRepresentation(tree*& anyTree);
    static void printFrequency(fileinfo*& anyFile);
    static void printBitString(fileinfo *&anyFile);
    static void printTree(node* anyNode, int level = 0);

    static void printAll(tree *anyTree, node *anyNode, fileinfo *&anyFile);
};

#endif // PRINTER_H
