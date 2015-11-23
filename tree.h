#ifndef TREE_H
#define TREE_H
#include"fileinfo.h"
#include "node.h"

class tree
{
    node* root;
    QByteArray m_representation, m_header;
    QList<node*> m_list;
    QVector<QString> m_vector;

public:
    tree(fileinfo*& anyFile);
    ~tree();

    static bool compare(node *x, node *y);
    void representation(node *anyNode);
    void toList(fileinfo*& anyFile);
    void buildHeader(QString anyPath, QByteArray anyCodification, int anyTrash);
    void toVector(const node* anyNode, QString temp = "");

    node* getRoot();
    QVector<QString> getVector();
    QString getRepresentation() const;
    QList<node *> getList() const;
    QByteArray getHeader() const;
};

#endif // TREE_H
