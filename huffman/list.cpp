#include "list.h"



bool list::compare(const node *x, const node *y){
    if(x->getRepetition() == y->getRepetition()){
        return x->getSymbol() < y->getSymbol();
    }
    return x->getRepetition() < y->getRepetition();
}

QList<node *> list::toQList(int *array){
    QList<node*> list;
    for(int aux = 0; aux<256; aux++){
        if(array[aux] != 0) list << new node(array[aux],true,aux);
    }
    qSort(list.begin(), list.end(), compare);
    return list;

}

QList<node *> list::read(QString path)
{
    int counter[256] = {0};
    QFile *file = new QFile(path);
    if(file->open(QIODevice::ReadOnly)){
        QByteArray array = file->readAll();
        for(int aux = 0; aux < array.at(aux); aux++){
             counter[(unsigned char)(array.at(aux))]++;
        }
    }
    return toQList(counter);
}
void list::print(int* text){
    for(int i = 0 ; i < 256 ; ++i) {
        if(text[i]) qDebug() << "ASCII:" << (int) char(i) << "value:"<< char(i) << "frequency:" << text[i];
    }
}
