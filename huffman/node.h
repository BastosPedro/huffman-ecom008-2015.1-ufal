#ifndef NODE_H
#define NODE_H

class node
{
public:
    int m_symbol, m_repetition;
    bool m_leaf;
    node *m_leftchild;
    node *m_rightchild;

    node(int repetition, int symbol, node* leftchild, node* rightchild);
    ~node();

    node *getLeftchild() const;
    node *getRightchild() const;

    void setBoth(node *leftchild, node *rightchild);
    bool isLeaf() const;

    int getSymbol() const;
    void setSymbol(int symbol);

    int getRepetition() const;
    void setRepetition(int repetition);
};

#endif // NODE_H
