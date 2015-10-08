#include "auxilia.h"


int main() {

    QTime temporis;
    temporis.start();

    encode* roma = new encode;
    roma->setPath("/home/pedro/Documents/samples/bolsadablackberry.jpg");
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toHash(invicta->getRoot());
    invicta->representation(invicta->getRoot());

    roma->setBitString(invicta->getHash());

    auxilia::printAll(invicta, invicta->getRoot(), roma);

    qDebug("temporis: %d ms", temporis.elapsed());
}
