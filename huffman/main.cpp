#include "auxilia.h"


int main() {

    compression* roma = new compression;
    roma->setPath("/home/pedro/Documents/atahualpa.txt");
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toHash(invicta->getRoot());
    invicta->representation(invicta->getRoot());

    roma->setBitString(invicta->getHash());

    auxilia::printAll(invicta, invicta->getRoot(), roma);
}
