#ifndef read_H
#define read_H
#include <QString>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QIODevice>

class read {
    public:
        read();

        int * countFreq(QString dir);

    private:
        int m_frequency[256] = {0};
};

#endif // read_H
