#include "tree.h"

tree::tree(fileinfo*& anyFile)
{
    root = 0;
    toList(anyFile);
    m_vector = QVector<QString>(256,"");
    Q_ASSERT_X(!m_list.isEmpty(), Q_FUNC_INFO, "Cannot build this tree :(");
    qint64 listSize = m_list.size();

    /*while(m_list.length() > 2){
        node* temp = new node(0,  m_list.at(0)->getRepetition()
                                + m_list.at(1)->getRepetition(),
                                  m_list.at(0), m_list.at(1));
        temp->setBoth(m_list.at(0), m_list.at(1));
        m_list.removeFirst();
        m_list.removeFirst();
        m_list.prepend(temp);
        qSort(m_list.begin(), m_list.end(), compare);
    }
    if(m_list.length() == 2){
        root = new node(0,  m_list.at(0)->getRepetition()
                          + m_list.at(1)->getRepetition(),
                            m_list.at(0), m_list.at(1));
        root->setBoth(m_list.at(0), m_list.at(1));
        qDebug() << "- Succesfully built tree :)";
    }*/

    while(listSize > 1)
    {
        qSort(m_list.begin(), m_list.end(), compare);
        node * temp = new node('*', m_list.at(0)->getRepetition()
                                  + m_list.at(1)->getRepetition(),
                                    m_list.at(0), m_list.at(1));

        m_list.removeFirst();
        m_list.removeFirst();
        m_list.prepend(temp);
        --listSize;
    }

    root = m_list.at(0);
}

tree::tree(QByteArray anyArray)
{
    root = NULL;
    m_representation = anyArray;

    qDebug() << endl << "rebuilding tree:";
    root = rebuildTree(0);
}

tree::~tree() {}

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
   if(anyNode){
       if(anyNode->isLeaf()){
           uchar symbolNode = anyNode->getSymbol();

           if((symbolNode == '*') | (symbolNode == '!')){
                m_representation += '!';
            }

           m_representation += symbolNode;
           return;
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
    QString nameLength = QString::number(nameFile.size(), 2);
    if(trash.length() < 3){
        trash.prepend(QString('0').repeated(3-trash.length()));
    }
    if(treeLength.length() < 13){
        treeLength.prepend(QString('0').repeated(13-treeLength.length()));
    }
    if(nameLength.length() < 8){
        nameLength.prepend(QString('0').repeated(8-nameLength.length()));
    }
    qDebug() << endl << "trash, treelength, namelength, binlength:" << endl
             << trash << treeLength << nameLength << anyCodification.length() << endl;
    m_header += binaryStuff::setHeaderString(trash + treeLength + nameLength);
    qDebug() << "after trash, tree & nameLength:" << endl << m_header.toHex();
    m_header += nameFile.toLocal8Bit();
    qDebug() << "after nameFile" << endl << m_header.toHex();
    m_header += m_representation;
    //qDebug() << "after representation" << endl << m_header.toHex();
    m_header += binaryStuff::setHeaderString(anyCodification);
    //qDebug() << "after codification" << endl << m_header.toHex();
}

//the methods below are used in the decompression

node* tree::rebuildTree(int size)
{
    if(m_representation != ""){
        uchar curr = m_representation.at(0);
        m_representation.remove(0, 1);
        if(curr == '*'){
            qDebug() << "added:" << curr;
            return new node(rebuildTree(size+1), rebuildTree(size+1));
        }
        else{
            if(curr == '!'){
                curr = m_representation.at(0);
                m_representation.remove(0, 1);
            }
            qDebug() << "added:" << curr;
            return new node(curr, 0, NULL, NULL);
        }
    }
    else return NULL;

    /*if(current)
    {
        if(m_representation.isEmpty())
            return;
        else
        {
            uchar holderChar = m_representation[0];

            if(holderChar == '!')
            {
                holderChar = (uchar (m_representation[1]));
                current->setSymbol(holderChar);
                current->setRepetition(1);
                current->setBoth(0,0);
                m_representation.remove(0,2);
                return;
            }
            else if(holderChar == '*')
            {
                current->setSymbol(holderChar);
                current->setRepetition(0);
                current->setBoth((new node()),(new node()));

                node *subTree = current->getLeftchild();

                rebuildTree(subTree);
                subTree = current->getRightchild();
                rebuildTree(subTree);

                m_representation.remove(0,1);
                return;
            }
            else
            {
                current->setSymbol(holderChar);
                current->setRepetition(1);
                current->setBoth(0,0);
                m_representation.remove(0,1);
                return;
            }
        }
    }*/
}


void tree::decodeTheCode(QVector<bool> anyFile)
{

    int fileSize = anyFile.size();
    node* curr = root;
    for(int count = 0; count < fileSize; count++){
        if(anyFile.at(count)){
            curr = curr->getRightchild();
        }
        else{
            curr = curr->getLeftchild();
        }
        if(curr->isLeaf()){
            decoded.append(curr->getSymbol());
            curr = root;
        }
    }

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

QByteArray tree::getDecoded() const
{
    return decoded;
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

void tree::toList(fileinfo*& anyFile){
    for(int count = 0; count < 256; count++) {
            if(anyFile->getFrequency()[count]) {
            node * temp = new node(count, anyFile->getFrequency()[count], NULL, NULL);
            m_list.append(temp);
        }
    }
    //qSort(m_list.begin(), m_list.end(), compare);
}
