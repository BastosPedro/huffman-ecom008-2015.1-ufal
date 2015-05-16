#include"read.h"

read::read(){
    for(int count = 0; count < 256; count++){
        m_frequency[count] = 0;
    }
}

int * read::countFreq(QString dir){
    QFile *file = new QFile(dir);
    if(file->open(QIODevice::ReadOnly)) {
        QByteArray theFile = file->readAll();
        for (int var = 0 ; var < theFile.size() ; ++var) {
            m_frequency[uchar(theFile.at(var))]++;
        }
    }else return NULL;

    return m_frequency;
}
