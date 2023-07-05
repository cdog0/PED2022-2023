#ifndef TLISTAPOS_H
#define TLISTAPOS_H

#include "tlistanodo.h"

class TListaPos {
public:
    TListaNodo* pos;
    TListaPos();
    TListaPos(const TListaPos& otro);
    ~TListaPos();
    TListaPos& operator=(const TListaPos& otro);
    bool operator==(const TListaPos& otro);
    bool operator!=(const TListaPos& otro);
    TListaPos Anterior();
    TListaPos Siguiente();
    bool EsVacia();
};

#endif
