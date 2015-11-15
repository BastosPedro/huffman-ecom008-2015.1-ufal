#ifndef TREE_H
#define TREE_H

#include "fileinfo.h"
#include "node.h"

class tree
{
    node* root;
    //QString* m_array;
    QList<node*> m_list;
    QByteArray m_representation;
    QVector<uchar> m_vector;
    //QHash<uchar, QString> m_hash;

public:
    tree(fileinfo*& anyFile);
    ~tree();

    void toArray(node *anyNode);

    void toList(fileinfo*& anyFile);
    static bool compare(node *x, node *y);

    void representation(node *anyNode);
    QByteArray getRepresentation() const;

    QVector<uchar> getVector();
    QHash<unsigned char, QString> getHash();
    QVector<uchar> toVector(node* anyNode, QString temp = "");

    node* getRoot();
    QList<node *> getList() const;
};

#endif // TREE_H
