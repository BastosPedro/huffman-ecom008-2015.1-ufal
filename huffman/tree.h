#ifndef TREE_H
#define TREE_H

#include <QDebug>
#include <QHash>
#include <QList>
#include "compression.h"
#include "node.h"
//#include "auxilia.h"

class tree
{
public:
    node* root;
    QList<node*> m_list;
    QByteArray m_representation;
    QHash<uchar, QString> m_hash;

    tree(compression*& anyFile);
    ~tree();

    void toList(compression*& anyFile);
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
