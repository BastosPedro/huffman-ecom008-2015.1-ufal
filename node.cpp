#include "node.h"

node *node::getLeftchild() const
{
    return m_leftchild;
}

node *node::getRightchild() const
{
    return m_rightchild;
}


unsigned char node::getSymbol() const
{
    return m_symbol;
}

int node::getRepetition() const
{
    return m_repetition;
}

void node::setBoth(node *leftchild, node *rightchild)
{
    m_leftchild = leftchild;
    m_rightchild = rightchild;
}

void node::setSymbol(unsigned char symbol)
{
    m_symbol = symbol;
}

void node::setRepetition(int repetition)
{
    m_repetition = repetition;
}

bool node::isLeaf() const
{
    if(m_leftchild == 0 && m_rightchild == 0) return true;
    else return false;
}

node::node(unsigned char symbol, int repetition, node *leftchild, node *rightchild)
{
    m_symbol = symbol;
    m_repetition = repetition;
    m_leftchild = leftchild;
    m_rightchild = rightchild;

}

node::node(unsigned char a)
{
    m_symbol = a;
    m_leftchild = 0;
    m_rightchild = 0;
}

node::~node()
{

}
