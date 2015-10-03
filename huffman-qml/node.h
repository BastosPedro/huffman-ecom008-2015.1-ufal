#ifndef NODE_H
#define NODE_H

class node
{
public:
    unsigned char m_symbol;
    int m_repetition;
    bool m_leaf;
    node *m_leftchild;
    node *m_rightchild;

    node(int repetition, unsigned char symbol, node* leftchild, node* rightchild);
    ~node();

    node *getLeftchild() const;
    node *getRightchild() const;

    void setBoth(node *leftchild, node *rightchild);
    bool isLeaf() const;

    unsigned char getSymbol() const;
    void setSymbol(unsigned char symbol);

    int getRepetition() const;
    void setRepetition(int repetition);
};

#endif // NODE_H
