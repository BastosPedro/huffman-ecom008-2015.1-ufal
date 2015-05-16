#include "node.h"


int node::getSymbol() const
{
    return symbol;
}

void node::setSymbol(int value)
{
    symbol = value;
}

int node::getRepetition() const
{
    return repetition;
}

void node::setRepetition(int value)
{
    repetition = value;
}

node *node::getLeftchild() const
{
    return leftchild;
}

void node::setLeftchild(node *value)
{
    leftchild = value;
}

node *node::getRightchild() const
{
    return rightchild;
}

void node::setRightchild(node *value)
{
    rightchild = value;
}
node::node(int repetition, int symbol)
{
    this->repetition = repetition;
    this->symbol = symbol;
    this->leftchild = 0;
    this->rightchild = 0;
}

node::~node()
{
    
}

