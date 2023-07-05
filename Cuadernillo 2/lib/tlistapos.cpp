#include "tlistapos.h"

TListaPos::TListaPos() : pos(nullptr) {}

TListaPos::TListaPos(const TListaPos& otro) : pos(otro.pos) {}

TListaPos::~TListaPos() {}

TListaPos& TListaPos::operator=(const TListaPos& otro) {
    if (this != &otro) {
        pos = otro.pos;
    }
    return *this;
}

bool TListaPos::operator==(const TListaPos& otro) {
    return pos == otro.pos;
}

bool TListaPos::operator!=(const TListaPos& otro) {
    return pos != otro.pos;
}

TListaPos TListaPos::Anterior() {
    TListaPos anterior;
    anterior.pos = (pos != nullptr) ? pos->anterior : nullptr;
    return anterior;
}

TListaPos TListaPos::Siguiente() {
    TListaPos siguiente;
    siguiente.pos = (pos != nullptr) ? pos->siguiente : nullptr;
    return siguiente;
}

bool TListaPos::EsVacia() {
    return pos == nullptr;
}
