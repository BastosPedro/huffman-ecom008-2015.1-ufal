#include <QDebug>
#include <QString>
#include "huffman.h"
int main() {
    huffman *p = new huffman();
    int *contador = p->countFreq("//home//pedro//Documents//códigos//teste.txt");
    for( int i = 0 ; i < 256 ; ++i) {
        if(contador[i]) qDebug() << "ASCII:" << (int) char(i) << "value:"<< char(i) << "frequency:" << contador[i];
    }
   return 0;
}
