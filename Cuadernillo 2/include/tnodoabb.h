#ifndef TNODOABB_H
#define TNODOABB_H

#include "tcomplejo.h"

class TNodoABB {
private:
    TComplejo item;
    TNodoABB* iz;
    TNodoABB* de;

public:
    TNodoABB();
    TNodoABB(const TNodoABB& nodo);
    ~TNodoABB();
    TNodoABB& operator=(const TNodoABB& nodo);

    friend class TABBCom;
};

#endif  // TNODOABB_H
