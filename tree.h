#ifndef TREE_H
#define TREE_H

#include "binarystuff.h"
#include "node.h"

class tree
{
    node* root;
    QString m_representation;
    QString m_header;
    QList<node*> m_list;
    QVector<uchar> m_vector;

public:
    tree(fileinfo*& anyFile);
    ~tree();

    static bool compare(node *x, node *y);
    void representation(node *anyNode);
    void toList(fileinfo*& anyFile);
    void buildHeader(QString anyPath, int anyTrash);
    QVector<uchar> toVector(node* anyNode, QString temp = "");

    node* getRoot();
    QVector<uchar> getVector();
    QString getRepresentation() const;
    QList<node *> getList() const;
};

#endif // TREE_H
