#include "tree.h"
//#include "auxilia.h"



QList<node *> tree::getList() const
{
    return m_list;
}

QByteArray tree::getRepresentation() const
{
    return m_representation;
}
tree::tree(compression*& anyFile)
{
    root = 0;
    toList(anyFile);

    Q_ASSERT_X(m_list.length() >= 2, Q_FUNC_INFO, "Cannot build this tree.");

    while(m_list.length() > 2){
        qSort(m_list.begin(), m_list.end(), compare);
        node* temp = new node(0, m_list.at(0)->getRepetition() + m_list.at(1)->getRepetition(), m_list.at(0), m_list.at(1));
        temp->setBoth(m_list.at(0), m_list.at(1));
        m_list.removeFirst();
        m_list.removeFirst();
        m_list.insert(0, temp);
    }
    if(m_list.length() == 2){
        root = new node(0, m_list.at(0)->getRepetition() + m_list.at(1)->getRepetition(), m_list.at(0), m_list.at(1));
        //root->setBoth(m_list.at(0), m_list.at(1));
        m_list.removeFirst();
        m_list.removeFirst();
        m_list.insert(0,root);
        qDebug() << "- Succesfully built tree :)";
    }
    else{
        qDebug() << "Tree Constructor - Fail :(";
    }
}

tree::~tree()
{

}
void tree::toList(compression*& anyFile){
    for(int count = 0; count < 256; count++) {
            if(anyFile->getFrequency()[count]) {
            node * temp = new node(count, anyFile->getFrequency()[count], NULL, NULL);
            m_list.append(temp);
        }
    }
    qSort(m_list.begin(), m_list.end(), compare);
}

bool tree::compare(node *x, node *y)
{
    if(x->getRepetition() == y->getRepetition()){
        return x->getSymbol() < y->getSymbol();
    }
    return x->getRepetition() < y->getRepetition();
}

QHash<uchar, QString> tree::toHash(node* anyNode, QString temp)
{
    Q_ASSERT_X(root, Q_FUNC_INFO, "Cannot use this tree.");
    if(anyNode->isLeaf()){
        m_hash.insert(anyNode->getSymbol(), temp);
        qDebug() << "node" << anyNode->getSymbol() << "\nAddded with coding:" << qPrintable(temp);
    }
    else{
        temp += '0';
        toHash(anyNode->getLeftchild(), temp);
        temp = temp.mid(0, temp.length()-1);
        temp += '1';
        toHash(anyNode->getRightchild(), temp);
    }
    return m_hash;
}

QByteArray tree::representation(node *anyNode)
{
    QByteArray auxRepresentation;
    if(anyNode->isLeaf()){
        if((anyNode->getSymbol() == 0x21) || (anyNode->getSymbol() == 0x2A)){
            auxRepresentation.append(0x21);
        }
        auxRepresentation.append(anyNode->getSymbol());
        return auxRepresentation;
    }
    else{
        auxRepresentation.append(0x2A);
        auxRepresentation += representation(anyNode->getLeftchild()) + representation(anyNode->getRightchild());
    }
    return auxRepresentation;
}

void tree::formalizing(node *anyNode)
{
    m_representation = representation(anyNode);
    m_representation.remove(0,1);
}

node *tree::getRoot()
{
    return root;
}

QHash<unsigned char, QString> tree::getHash()
{
    if(root!=0){
        toHash(root);
        qDebug() << "- Succesful node coding. Yay!";
    }
    return m_hash;
}


