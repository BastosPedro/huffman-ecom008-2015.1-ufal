#include "tree.h"

tree::tree(fileinfo*& anyFile)
{
    root = 0;
    toList(anyFile);

    Q_ASSERT_X(m_list.length() >= 2, Q_FUNC_INFO, "Cannot build this tree :(");

    while(m_list.length() > 2){
        node* temp = new node(0,  m_list.at(0)->getRepetition()
                                + m_list.at(1)->getRepetition(),
                                  m_list.at(0), m_list.at(1));
        temp->setBoth(m_list.at(0), m_list.at(1));
        m_list.removeFirst();
        m_list.removeFirst();
        m_list.insert(0, temp);
        qSort(m_list.begin(), m_list.end(), compare);
    }
    if(m_list.length() == 2){
        root = new node(0,  m_list.at(0)->getRepetition()
                          + m_list.at(1)->getRepetition(),
                            m_list.at(0), m_list.at(1));
        root->setBoth(m_list.at(0), m_list.at(1));
        qDebug() << "- Succesfully built tree :)";
    }
}

tree::tree()
{

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

void tree::toVector(const node* anyNode, QString temp)
{
    Q_ASSERT_X(root, Q_FUNC_INFO, "Cannot use this tree.");
    //QVector<QString> anyVector(256);
    m_vector.resize(256);

    if(anyNode->isLeaf()){
        m_vector.insert(anyNode->getSymbol(), temp);
        qDebug() << "node" << anyNode->getSymbol() << "\nAddded with coding:" << qPrintable(temp);
    }
    else{
        temp += '0';
        toVector(anyNode->getLeftchild(), temp);
        temp.chop(1);
        temp += '1';
        toVector(anyNode->getRightchild(), temp);
    }
}

void tree::representation(node *anyNode)
{
   if(anyNode != 0){
       if(anyNode->isLeaf()){
           if((uchar(anyNode->getSymbol() == '*')) || (uchar (anyNode->getSymbol() == '!'))){
                m_representation += '!';
            }
            m_representation += anyNode->getSymbol();
        }
        else{
            m_representation += '*';
            representation(anyNode->getLeftchild());
            representation(anyNode->getRightchild());
        }
   }
}

void tree::buildHeader(QString anyPath, QByteArray anyCodification, int anyTrash)
{
    m_representation.clear();
    representation(root);
    QString trash = QString::number(anyTrash, 2);
    QString treeLength = QString::number(m_representation.size(), 2);
    QString nameFile = QFileInfo(anyPath).fileName();
    if(trash.length() < 3){
        trash.prepend(QString('0').repeated(3-trash.length()));
    }
    if(treeLength.length() < 13){
        treeLength.prepend(QString('0').repeated(13-treeLength.length()));
    }
    qDebug() << endl << "trash, treelength, namelength, binlength:" << endl
             << trash << treeLength << nameFile.length() << anyCodification.length() << endl;
    m_header.append(binaryStuff::setHeaderString(trash));
    qDebug() << "after trash:" << endl << m_header.toHex();
    m_header.append(binaryStuff::setHeaderString(treeLength));
    qDebug() << "after treeLength" << endl << m_header.toHex();
    m_header += nameFile.length();
    qDebug() << "after nameLength" << endl << m_header.toHex();
    m_header += nameFile;
    qDebug() << "after nameFile" << endl << m_header.toHex();
    m_header += m_representation;
    qDebug() << "after representation" << endl << m_header.toHex();
    m_header += binaryStuff::setHeaderString(anyCodification);
    qDebug() << "after codification" << endl << m_header.toHex();
    m_header += binaryStuff::setHeaderString(QString('0').repeated(anyTrash));
    qDebug() << "after trash";
    qDebug() << endl << "after all" << endl << m_header.toHex();
}

//the methods below are used in the decompression

node *tree::rebuildTree(QByteArray anyRep)
{
    if(anyRep != ""){
        uchar curr = anyRep.at(0);
        if(curr == '*'){
            qDebug() << "current node:" << curr;
            anyRep.remove(0,1);
            node* temp = new node(curr, 0,
                                rebuildTree(anyRep),
                                rebuildTree(anyRep));
            //rebuildTree(anyRep);
        }
        else if(curr == '!'){
            qDebug() << "current node:" << curr;
            anyRep.remove(0,1);
            node* temp = new node(anyRep.at(1), 0,
                                rebuildTree(anyRep),
                                rebuildTree(anyRep));
        }
        else{
            qDebug() << "current node:" << curr;
            anyRep.remove(0,1);
            node* temp = new node(curr, 0, 0, 0);
        }
    }
        //root->setBoth(anyRep.at(0), anyRep.at(1));
        qDebug() << "tree rebuilt";
}

void tree::decodeTheCode(QByteArray anyFile, int anyTrash)
{
    decoded = binaryStuff::bytetheBit(anyFile.size(), anyFile);
    decoded.resize(decoded.size() - anyTrash);
}

// Getters, Setters, etc //
QList<node *> tree::getList() const
{
    return m_list;
}

QString tree::getRepresentation() const
{
    return m_representation;
}

QVector<QString> tree::getVector()
{
   return m_vector;
}

node *tree::getRoot()
{
    return root;
}

QByteArray tree::getHeader() const
{
    return m_header;
}


bool tree::compare(node *x, node *y)
{
    if(x->getRepetition() == y->getRepetition()){
        return x->getSymbol() < y->getSymbol();
    }
    return x->getRepetition() < y->getRepetition();
}
