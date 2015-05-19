#ifndef NODE_H
#define NODE_H
#include<QString>


class node
{
public:
    unsigned char m_symbol;
    unsigned int m_repetition;
    bool leaf;
    node *leftchild;
    node *rightchild;

    node(unsigned int m_repetition, bool leaf, char m_symbol = 0);

    ~node();

    node *getLeftchild() const;
    node *getRightchild() const;

    void setBoth(node *leftchild, node *rightchild);
    bool isLeaf() const;

    unsigned char getSymbol() const;
    void setSymbol(unsigned char symbol);

    unsigned int getRepetition() const;
    void setRepetition(unsigned int repetition);
};

#endif // NODE_H
