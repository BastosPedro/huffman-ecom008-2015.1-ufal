#include "tree.h"

tree::tree(fileinfo*& anyFile)
{
    root = 0;
    toList(anyFile);

    Q_ASSERT_X(m_list.length() >= 2, Q_FUNC_INFO, "Cannot build this tree :(");

    while(m_list.length() > 2){
        qSort(m_list.begin(), m_list.end(), compare);
        node* temp = new node(0,  m_list.at(0)->getRepetition()
                                + m_list.at(1)->getRepetition(),
                                  m_list.at(0), m_list.at(1));
        temp->setBoth(m_list.at(0), m_list.at(1));
        m_list.removeFirst();
        m_list.removeFirst();
        m_list.insert(0, temp);
    }
    if(m_list.length() == 2){
        root = new node(0,  m_list.at(0)->getRepetition()
                          + m_list.at(1)->getRepetition(),
                            m_list.at(0), m_list.at(1));
        root->setBoth(m_list.at(0), m_list.at(1));
        qDebug() << "- Succesfully built tree :)";
    }
}

tree::~tree()
{

}

void tree::toList(fileinfo*& anyFile){
    for(int count = 0; count < 256; count++) {
            if(anyFile->getFrequency()[count]) {
            node * temp = new node(count, anyFile->getFrequency()[count], NULL, NULL);
            m_list.append(temp);
        }
    }
    qSort(m_list.begin(), m_list.end(), compare);
}

QVector<uchar> tree::toVector(node* anyNode, QString temp)
{
    Q_ASSERT_X(root, Q_FUNC_INFO, "Cannot use this tree.");
    QVector<uchar> anyVector;
    if(anyNode->isLeaf()){
        anyVector.append(anyNode->getSymbol());
        qDebug() << "node" << anyNode->getSymbol() << "\nAddded with coding:" << qPrintable(temp);
    }
    else{
        temp += '0';
        toVector(anyNode->getLeftchild(), temp);
        temp = temp.mid(0, temp.length()-1);
        temp += '1';
        toVector(anyNode->getRightchild(), temp);
    }
    return anyVector;
}

void tree::representation(node *anyNode)
{
    if(anyNode->isLeaf()){
        if(uchar(anyNode->getSymbol() == '*') || anyNode->getSymbol() == '!'){
            m_representation.append('!');
        }
        m_representation.append(anyNode->getSymbol());
    }
    else{
        m_representation.append('*');
        representation(anyNode->getLeftchild());
        representation(anyNode->getRightchild());
    }
}

bool tree::compare(node *x, node *y)
{
    if(x->getRepetition() == y->getRepetition()){
        return x->getSymbol() < y->getSymbol();
    }
    return x->getRepetition() < y->getRepetition();
}
// Getters //
QList<node *> tree::getList() const
{
    return m_list;
}

QByteArray tree::getRepresentation() const
{
    return m_representation;
}

QVector<uchar> tree::getVector()
{
   if(root!=0){
       m_vector = toVector(root);
       qDebug() << "- Succesful node coding.";
   }
   return m_vector;
}

node *tree::getRoot()
{
    return root;
}

