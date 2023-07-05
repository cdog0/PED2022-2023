//
// Created by carlo on 13/06/2023.
//

#ifndef TLISTANODO_H
#define TLISTANODO_H

#include "tcomplejo.h"

class TListaNodo {
private:
    TComplejo e;
    TListaNodo* anterior;
    TListaNodo* siguiente;

public:
    TListaNodo();
    TListaNodo(const TListaNodo& otro);
    ~TListaNodo();
    TListaNodo& operator=(const TListaNodo& otro);

    friend class TListaPos;
    friend class TListaCom;
};

#endif

