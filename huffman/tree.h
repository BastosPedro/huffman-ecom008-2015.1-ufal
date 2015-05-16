#ifndef TREE_H
#define TREE_H


class tree
{
public:
    tree();
    ~tree();
    void add(char symbol);
    void addSubTree(node * node);
    void toLeft();
    void toRight();
};

#endif // TREE_H
