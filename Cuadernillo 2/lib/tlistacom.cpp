#include "tlistacom.h"

TListaCom::TListaCom() : primero(nullptr), ultimo(nullptr) {}

TListaCom::TListaCom(const TListaCom& otro) : primero(nullptr), ultimo(nullptr) {
    TListaPos pos = otro.Primera();
    while (!pos.EsVacia()) {
        TComplejo complejo = otro.Obtener(pos);
        InsertarD(complejo, Ultima());
        pos = otro.Siguiente(pos);
    }
}

TListaCom::~TListaCom() {
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        TListaNodo* nodo = pos.pos;
        pos = Siguiente(pos);
        delete nodo;
    }
}

TListaCom& TListaCom::operator=(const TListaCom& otro) {
    if (this != &otro) {
        // Liberar la lista actual
        TListaPos pos = Primera();
        while (!pos.EsVacia()) {
            TListaNodo* nodo = pos.pos;
            pos = Siguiente(pos);
            delete nodo;
        }

        // Copiar la lista "otro"
        primero = nullptr;
        ultimo = nullptr;
        pos = otro.Primera();
        while (!pos.EsVacia()) {
            TComplejo complejo = otro.Obtener(pos);
            InsertarD(complejo, Ultima());
            pos = otro.Siguiente(pos);
        }
    }
    return *this;
}

bool TListaCom::operator==(const TListaCom& otro) {
    TListaPos pos1 = Primera();
    TListaPos pos2 = otro.Primera();

    while (!pos1.EsVacia() && !pos2.EsVacia()) {
        if (Obtener(pos1) != otro.Obtener(pos2)) {
            return false;
        }
        pos1 = Siguiente(pos1);
        pos2 = otro.Siguiente(pos2);
    }

    return pos1.EsVacia() && pos2.EsVacia();
}

bool TListaCom::operator!=(const TListaCom& otro) {
    return !(*this == otro);
}

TListaPos TListaCom::Primera() const{
    TListaPos pos;
    pos.pos = primero;
    return pos;
}

TListaPos TListaCom::Ultima() const{
    TListaPos pos;
    pos.pos = ultimo;
    return pos;
}

bool TListaCom::EsVacia() {
    return primero == nullptr;
}

bool TListaCom::InsCabeza(TComplejo& complejo) {
    TListaNodo* nodo = new TListaNodo();
    if (nodo == nullptr) {
        return false;
    }

    nodo->e = complejo;
    nodo->siguiente = primero;
    if (primero != nullptr) {
        primero->anterior = nodo;
    } else {
        ultimo = nodo;
    }
    primero = nodo;
    return true;
}

bool TListaCom::InsertarI(TComplejo& complejo, TListaPos& pos) {
    if (pos.EsVacia()) {
        return false;
    }

    TListaNodo* nodo = new TListaNodo();
    if (nodo == nullptr) {
        return false;
    }

    nodo->e = complejo;
    nodo->anterior = pos.pos->anterior;
    nodo->siguiente = pos.pos;
    if (pos.pos->anterior != nullptr) {
        pos.pos->anterior->siguiente = nodo;
    } else {
        primero = nodo;
    }
    pos.pos->anterior = nodo;
    return true;
}

bool TListaCom::InsertarD(TComplejo& complejo, TListaPos& pos) {
    if (pos.EsVacia()) {
        return false;
    }

    TListaNodo* nodo = new TListaNodo();
    if (nodo == nullptr) {
        return false;
    }

    nodo->e = complejo;
    nodo->anterior = pos.pos;
    nodo->siguiente = pos.pos->siguiente;
    if (pos.pos->siguiente != nullptr) {
        pos.pos->siguiente->anterior = nodo;
    } else {
        ultimo = nodo;
    }
    pos.pos->siguiente = nodo;
    return true;
}

bool TListaCom::Borrar(TComplejo& complejo) {
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        if (Obtener(pos) == complejo) {
            return Borrar(pos);
        }
        pos = Siguiente(pos);
    }
    return false;
}

bool TListaCom::BorrarTodos(TComplejo& complejo) {
    bool borrado = false;
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        if (Obtener(pos) == complejo) {
            Borrar(pos);
            borrado = true;
        } else {
            pos = Siguiente(pos);
        }
    }
    return borrado;
}

bool TListaCom::Borrar(TListaPos& pos) {
    if (pos.EsVacia()) {
        return false;
    }

    TListaNodo* nodo = pos.pos;
    if (nodo->anterior != nullptr) {
        nodo->anterior->siguiente = nodo->siguiente;
    } else {
        primero = nodo->siguiente;
    }
    if (nodo->siguiente != nullptr) {
        nodo->siguiente->anterior = nodo->anterior;
    } else {
        ultimo = nodo->anterior;
   }

    delete nodo;
    pos.pos = nullptr;
    return true;
}

TComplejo TListaCom::Obtener(TListaPos& pos) {
    if (pos.EsVacia()) {
        return TComplejo();
    }
    return pos.pos->e;
}

bool TListaCom::Buscar(TComplejo& complejo) {
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        if (Obtener(pos) == complejo) {
            return true;
        }
        pos = Siguiente(pos);
    }
    return false;
}

int TListaCom::Longitud() {
    int longitud = 0;
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        longitud++;
        pos = Siguiente(pos);
    }
    return longitud;
}

std::ostream& operator<<(std::ostream& os, TListaCom& lista) {
    TListaPos pos = lista.Primera();
    os << "[";
    while (!pos.EsVacia()) {
        os << lista.Obtener(pos);
        pos = lista.Siguiente(pos);
        if (!pos.EsVacia()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
#include "tlistacom.h"

TListaCom::TListaCom() : primero(nullptr), ultimo(nullptr) {}

TListaCom::TListaCom(const TListaCom& otro) : primero(nullptr), ultimo(nullptr) {
    TListaPos pos = otro.Primera();
    while (!pos.EsVacia()) {
        TComplejo complejo = otro.Obtener(pos);
        InsertarD(complejo, Ultima());
        pos = otro.Siguiente(pos);
    }
}

TListaCom::~TListaCom() {
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        TListaNodo* nodo = pos.pos;
        pos = Siguiente(pos);
        delete nodo;
    }
}

TListaCom& TListaCom::operator=(const TListaCom& otro) {
    if (this != &otro) {
        // Liberar la lista actual
        TListaPos pos = Primera();
        while (!pos.EsVacia()) {
            TListaNodo* nodo = pos.pos;
            pos = Siguiente(pos);
            delete nodo;
        }

        // Copiar la lista "otro"
        primero = nullptr;
        ultimo = nullptr;
        pos = otro.Primera();
        while (!pos.EsVacia()) {
            TComplejo complejo = otro.Obtener(pos);
            InsertarD(complejo, Ultima());
            pos = otro.Siguiente(pos);
        }
    }
    return *this;
}

bool TListaCom::operator==(const TListaCom& otro) {
    TListaPos pos1 = Primera();
    TListaPos pos2 = otro.Primera();

    while (!pos1.EsVacia() && !pos2.EsVacia()) {
        if (Obtener(pos1) != otro.Obtener(pos2)) {
            return false;
        }
        pos1 = Siguiente(pos1);
        pos2 = otro.Siguiente(pos2);
    }

    return pos1.EsVacia() && pos2.EsVacia();
}

bool TListaCom::operator!=(const TListaCom& otro) {
    return !(*this == otro);
}

TListaPos TListaCom::Primera() {
    TListaPos pos;
    pos.pos = primero;
    return pos;
}

TListaPos TListaCom::Ultima() {
    TListaPos pos;
    pos.pos = ultimo;
    return pos;
}

bool TListaCom::EsVacia() {
    return primero == nullptr;
}

bool TListaCom::InsCabeza(TComplejo& complejo) {
    TListaNodo* nodo = new TListaNodo();
    if (nodo == nullptr) {
        return false;
    }

    nodo->e = complejo;
    nodo->siguiente = primero;
    if (primero != nullptr) {
        primero->anterior = nodo;
    } else {
        ultimo = nodo;
    }
    primero = nodo;
    return true;
}

bool TListaCom::InsertarI(TComplejo& complejo, TListaPos& pos) {
    if (pos.EsVacia()) {
        return false;
    }

    TListaNodo* nodo = new TListaNodo();
    if (nodo == nullptr) {
        return false;
    }

    nodo->e = complejo;
    nodo->anterior = pos.pos->anterior;
    nodo->siguiente = pos.pos;
    if (pos.pos->anterior != nullptr) {
        pos.pos->anterior->siguiente = nodo;
    } else {
        primero = nodo;
    }
    pos.pos->anterior = nodo;
    return true;
}

bool TListaCom::InsertarD(TComplejo& complejo, TListaPos& pos) {
    if (pos.EsVacia()) {
        return false;
    }

    TListaNodo* nodo = new TListaNodo();
    if (nodo == nullptr) {
        return false;
    }

    nodo->e = complejo;
    nodo->anterior = pos.pos;
    nodo->siguiente = pos.pos->siguiente;
    if (pos.pos->siguiente != nullptr) {
        pos.pos->siguiente->anterior = nodo;
    } else {
        ultimo = nodo;
    }
    pos.pos->siguiente = nodo;
    return true;
}

bool TListaCom::Borrar(TComplejo& complejo) {
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        if (Obtener(pos) == complejo) {
            return Borrar(pos);
        }
        pos = Siguiente(pos);
    }
    return false;
}

bool TListaCom::BorrarTodos(TComplejo& complejo) {
    bool borrado = false;
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        if (Obtener(pos) == complejo) {
            Borrar(pos);
            borrado = true;
        } else {
            pos = Siguiente(pos);
        }
    }
    return borrado;
}

bool TListaCom::Borrar(TListaPos& pos) {
    if (pos.EsVacia()) {
        return false;
    }

    TListaNodo* nodo = pos.pos;
    if (nodo->anterior != nullptr) {
        nodo->anterior->siguiente = nodo->siguiente;
    } else {
        primero = nodo->siguiente;
    }
    if (nodo->siguiente != nullptr) {
        nodo->siguiente->anterior = nodo->anterior;
    } else {
        ultimo = nodo->anterior;
   }

    delete nodo;
    pos.pos = nullptr;
    return true;
}

TComplejo TListaCom::Obtener(TListaPos& pos) {
    if (pos.EsVacia()) {
        return TComplejo();
    }
    return pos.pos->e;
}

bool TListaCom::Buscar(TComplejo& complejo) {
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        if (Obtener(pos) == complejo) {
            return true;
        }
        pos = Siguiente(pos);
    }
    return false;
}

int TListaCom::Longitud() {
    int longitud = 0;
    TListaPos pos = Primera();
    while (!pos.EsVacia()) {
        longitud++;
        pos = Siguiente(pos);
    }
    return longitud;
}

std::ostream& operator<<(std::ostream& os, TListaCom& lista) {
    TListaPos pos = lista.Primera();
    os << "[";
    while (!pos.EsVacia()) {
        os << lista.Obtener(pos);
        pos = lista.Siguiente(pos);
        if (!pos.EsVacia()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
