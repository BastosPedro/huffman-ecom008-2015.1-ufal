#ifndef TREE_H
#define TREE_H
#include<QDebug>
#include"node.h"
//#include"read.h"


class tree
{
public:
    node* root = 0;
    QHash<unsigned char, QString> hash;
    QList<node*> list;

    tree(QList<node*> list);
    ~tree();
    void printTree(node* node, int level = 0);
    node* get();
    QHash<unsigned char, QString> getHash();
    void huffcoding(node* node, QString temp = "");
};

#endif // TREE_H
