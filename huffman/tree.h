#ifndef TREE_H
#define TREE_H
#include<QDebug>
#include"list.h"
#include"node.h"
//#include"read.h"


class tree
{
public:
    node* root;
    QHash<unsigned char, QString> hash;
    QList<node*> list;

    tree(QList<node*> list);
    ~tree();

    void printTree(node* node, int level = 0);
    void huffcoding(node* node, QString temp = "");

    QByteArray representation(node *anyNode);
    QByteArray formalizing(node *anyNode);

    node* getRoot();
    QHash<unsigned char, QString> getHash();
};

#endif // TREE_H
