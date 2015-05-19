#include "tree.h"


tree::tree(QList<node *> list)
{
    this->list = list;
    while(list.length() > 2){
        node* temp = new node(list.at(0)->getRepetition() + list.at(1)->getRepetition(), false);
        temp->setBoth(list.at(0), list.at(1));
        list.removeFirst();
        list.removeFirst();
        list.insert(0, temp);
    }
    if(list.length() == 2){
        root = new node(list.at(0)->getRepetition() + list.at(1)->getRepetition(), false);
        root->setBoth(list.at(0), list.at(1));
        qDebug() << "Succesfully built tree :)";
    }
    else{
        qDebug() << "Fail :(";
    }
}

tree::~tree()
{

}

void tree::printTree(node *node, int level)
{
    if(node != 0){
        printTree(node->getRightchild(), level+1);
        if(node->isLeaf()){
            qDebug() <<
            qPrintable(QString("\t").repeated(level)) << char(node->getSymbol()) << "/" << node->getRepetition();
        }
        else{
            qDebug() << qPrintable(QString("\t").repeated(level)) << char(46);
        }
        printTree(node->getLeftchild(), level+1);
    }
}

node *tree::get()
{
    return root;
}

QHash<unsigned char, QString> tree::getHash()
{
    if(root!=0){
        huffcoding(root);
        qDebug() << "Succesful node coding";
    }
    return hash;
}

void tree::huffcoding(node *node, QString temp)
{
    if(node->isLeaf()){
        hash.insert(node->getSymbol(), temp);
        qDebug() << "node" << node->getSymbol() << "\nAddded with coding:" << qPrintable(temp);
    }
    else{
        temp += '0';
        huffcoding(node->getLeftchild(), temp);
        temp = temp.mid(0, temp.length()-1);
        temp += 1;
        huffcoding(node->getRightchild(), temp);
    }
}


