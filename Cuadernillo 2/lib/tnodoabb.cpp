#include "tnodoabb.h"

TNodoABB::TNodoABB() : iz(nullptr), de(nullptr) {}

TNodoABB::TNodoABB(const TNodoABB& nodo) : item(nodo.item) {
    if (nodo.iz != nullptr) {
        iz = new TNodoABB(*nodo.iz);
    } else {
        iz = nullptr;
    }
    if (nodo.de != nullptr) {
        de = new TNodoABB(*nodo.de);
    } else {
        de = nullptr;
    }
}

TNodoABB::~TNodoABB() {
    delete iz;
    delete de;
}

TNodoABB& TNodoABB::operator=(const TNodoABB& nodo) {
    if (this != &nodo) {
        item = nodo.item;
        delete iz;
        delete de;
        if (nodo.iz != nullptr) {
            iz = new TNodoABB(*nodo.iz);
        } else {
            iz = nullptr;
        }
        if (nodo.de != nullptr) {
            de = new TNodoABB(*nodo.de);
        } else {
            de = nullptr;
        }
    }
    return *this;
}
