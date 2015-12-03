#pragma once
//#ifndef MAINHUB_H
//#define MAINHUB_H

#include <QObject>
#include <printer.h>

class mainHub : public QObject
{
    Q_OBJECT
public:
    explicit mainHub(QObject *parent = 0);
    ~mainHub();
    Q_INVOKABLE static void cCommand(QString path, QString out = "");
    Q_INVOKABLE static void dCommand(QString path, QString dir = "");
};

//#endif // MAINHUB_H
