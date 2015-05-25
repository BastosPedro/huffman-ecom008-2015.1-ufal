#include "node.h"

node *node::getLeftchild() const
{
    return leftchild;
}

node *node::getRightchild() const
{
    return rightchild;
}

void node::setBoth(node *leftchild, node *rightchild)
{
    this->leftchild = leftchild;
    this->rightchild = rightchild;
}

bool node::isLeaf() const
{
    return leftchild == 0 && rightchild == 0;
}

unsigned char node::getSymbol() const
{
    return m_symbol;
}

void node::setSymbol(unsigned char symbol)
{
    m_symbol = symbol;
}

unsigned int node::getRepetition() const
{
    return m_repetition;
}

void node::setRepetition(unsigned int repetition)
{
    m_repetition = repetition;
}
node::node(unsigned int m_repetition, bool leaf, char m_symbol)
{
    this->m_symbol = m_symbol;
    this->m_repetition = m_repetition;
    this->leaf = leaf;
    this->leftchild = leftchild;
    this->rightchild = rightchild;

}

node::~node()
{
    
}

