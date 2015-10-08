#ifndef TREE_H
#define TREE_H

#include "encode.h"
#include "node.h"

class tree
{
    node* root;
    QList<node*> m_list;
    QByteArray m_representation;
    QHash<uchar, QString> m_hash;

public:
    tree(encode*& anyFile);
    ~tree();

    void toList(encode*& anyFile);
    void formalizing(node *anyNode);
    static bool compare(node *x, node *y);

    QByteArray representation(node *anyNode);
    QByteArray getRepresentation() const;

    QHash<unsigned char, QString> getHash();
    QHash<uchar, QString> toHash(node* anyNode, QString temp = "");

    node* getRoot();
    QList<node *> getList() const;
};

#endif // TREE_H
