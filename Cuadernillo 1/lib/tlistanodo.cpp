#include "tlistanodo.h"

TListaNodo::TListaNodo() : anterior(nullptr), siguiente(nullptr) {}

TListaNodo::TListaNodo(const TListaNodo& otro) : e(otro.e), anterior(nullptr), siguiente(nullptr) {}

TListaNodo::~TListaNodo() {}

TListaNodo& TListaNodo::operator=(const TListaNodo& otro) {
    if (this != &otro) {
        e = otro.e;
    }
    return *this;
}
