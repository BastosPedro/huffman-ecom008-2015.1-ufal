#include "node.h"

node *node::getLeftchild() const
{
    return m_leftchild;
}

node *node::getRightchild() const
{
    return m_rightchild;
}

void node::setBoth(node *leftchild, node *rightchild)
{
    m_leftchild = leftchild;
    m_rightchild = rightchild;
}

bool node::isLeaf() const
{
    if(m_leftchild == 0 && m_rightchild == 0) return true;
    else return false;
}

int node::getSymbol() const
{
    return m_symbol;
}

void node::setSymbol(int symbol)
{
    m_symbol = symbol;
}

int node::getRepetition() const
{
    return m_repetition;
}

void node::setRepetition(int repetition)
{
    m_repetition = repetition;
}
node::node(int repetition, int symbol, node *leftchild, node *rightchild)
{
    m_symbol = symbol;
    m_repetition = repetition;
    m_leftchild = leftchild;
    m_rightchild = rightchild;

}

node::~node()
{
    
}

