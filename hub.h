#ifndef HUB_H
#define HUB_H

#include "printer.h"

class hub : public QObject
{
    Q_OBJECT
public:
    explicit hub(QObject *parent = 0);
    Q_INVOKABLE static void cCommand(QString path, QString out = "");
    Q_INVOKABLE static void dCommand(QString path, QString dir = "");

signals:

public slots:
};

#endif // HUB_H
