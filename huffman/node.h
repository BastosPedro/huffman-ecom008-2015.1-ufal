#ifndef NODE_H
#define NODE_H


class node
{
public:
    int symbol;
    int repetition;
    node* leftchild;
    node* rightchild;

    node(int repetition, int symbol);

    ~node();


    unsigned char getSymbol() const;
    void setSymbol(int value);

    int getRepetition() const;
    void setRepetition(int value);


    node *getLeftchild() const;
    void setLeftchild(node *value);


    node *getRightchild() const;
    void setRightchild(node *value);
};

#endif // NODE_H
