#include "tree.h"

tree::tree(fileinfo*& anyFile)
{
    root = 0;
    toList(anyFile);
    //m_vector = QVector<QString>(256,"");
    m_vector.clear();
    m_vector.resize(256);
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

tree::tree(QByteArray anyArray)
{
    root = NULL;
    m_representation = anyArray;
    root = rebuildTree(m_representation.size());
    qDebug() << "tree rebuilt";
}

tree::~tree() {}

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

    if(anyNode->isLeaf()){
        //m_vector.insert(anyNode->getSymbol(), temp);
        m_vector[(quint8(anyNode->getSymbol()))] = temp;
        qDebug() << "node" << anyNode->getSymbol() << "\nAddded with coding:" << qPrintable(temp);
    }
    else{
        temp += '0';
        toVector(anyNode->getLeftchild(), temp);
        temp.chop(1);
        temp += '1';
        toVector(anyNode->getRightchild(), temp);
        temp.chop(1);
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
    m_header += binaryStuff::setHeaderString(trash + treeLength);
    qDebug() << "after trash&treeLength:" << endl << m_header.toHex();
    m_header += nameFile.length();
    qDebug() << "after nameLength" << endl << m_header.toHex();
    m_header += nameFile;
    qDebug() << "after nameFile" << endl << m_header.toHex();
    m_header += m_representation;
    qDebug() << "after representation" << endl << m_header.toHex();
    m_header += binaryStuff::setHeaderString(anyCodification);
    qDebug() << "after codification" << endl << m_header.toHex();
    //qDebug() << endl << "after all" << endl << m_header.toHex();
}

//the methods below are used in the decompression

node *tree::rebuildTree(int size)
{
    uchar curr = m_representation.at(0);
    m_representation.remove(0, 1);
    if(curr == '*'){
        qDebug() << "added:" << curr << endl;
        return new node(0, rebuildTree(size+1)->getRepetition() +
                           rebuildTree(size+1)->getRepetition(),
                           rebuildTree(size+1), rebuildTree(size+1));
    }
    else{
        if(curr == '!'){
            curr = m_representation.at(0);
            m_representation.remove(0, 1);
        }
        qDebug() << "added:" << curr << endl;
        return new node(curr, 0, 0, 0);
    }
}


void tree::decodeTheCode(QByteArray anyFile, int anyTrash)
{
    int aux = anyFile.size();
    for(int count = 0; count < aux; count++){

    }
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
