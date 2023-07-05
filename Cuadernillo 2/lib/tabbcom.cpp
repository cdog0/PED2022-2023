#include "tabbcom.h"

TABBCom::TABBCom() : nodo(nullptr) {}

TABBCom::TABBCom(const TABBCom& abb) {
    if (abb.nodo != nullptr) {
        nodo = new TNodoABB(*abb.nodo);
    } else {
        nodo = nullptr;
    }
}

TABBCom::~TABBCom() {
    delete nodo;
    nodo = nullptr;
}

TABBCom& TABBCom::operator=(const TABBCom& abb) {
    if (this != &abb) {
        delete nodo;
        if (abb.nodo != nullptr) {
            nodo = new TNodoABB(*abb.nodo);
        } else {
            nodo = nullptr;
        }
    }
    return *this;
}

bool TABBCom::operator==(const TABBCom& abb) const {
    return (nodo == nullptr && abb.nodo == nullptr) ||
           (nodo != nullptr && abb.nodo != nullptr && *nodo == *abb.nodo);
}

bool TABBCom::EsVacio() const {
    return nodo == nullptr;
}

bool TABBCom::Insertar(const TComplejo& complejo) {
    if (EsVacio()) {
        nodo = new TNodoABB();
        nodo->item = complejo;
        return true;
    } else if (complejo == nodo->item) {
        return false;
    } else if (complejo < nodo->item) {
        return nodo->iz->Insertar(complejo);
    } else {
        return nodo->de->Insertar(complejo);
    }
}

bool TABBCom::Borrar(const TComplejo& complejo) {
    if (EsVacio()) {
        return false;
    } else if (complejo == nodo->item) {
        if (nodo->iz == nullptr && nodo->de == nullptr) {
            delete nodo;
            nodo = nullptr;
        } else if (nodo->iz == nullptr) {
            TNodoABB* aux = nodo;
            nodo = nodo->de;
            aux->de = nullptr;
            delete aux;
        } else if (nodo->de == nullptr) {
            TNodoABB* aux = nodo;
            nodo = nodo->iz;
            aux->iz = nullptr;
            delete aux;
        } else {
            TComplejo sucesor = nodo->de->Raiz();
            nodo->item = sucesor;
            return nodo->de->Borrar(sucesor);
        }
        return true;
    } else if (complejo < nodo->item) {
        return nodo->iz->Borrar(complejo);
    } else {
        return nodo->de->Borrar(complejo);
    }
}

bool TABBCom::Buscar(const TComplejo& complejo) const {
    if (EsVacio()) {
        return false;
    } else if (complejo == nodo->item) {
        return true;
    } else if (complejo < nodo->item) {
        return nodo->iz->Buscar(complejo);
    } else {
        return nodo->de->Buscar(complejo);
    }
}

TComplejo TABBCom::Raiz() const {
    if (EsVacio()) {
        return TComplejo();
    } else {
        return nodo->item;
    }
}

int TABBCom::Altura() const {
    if (EsVacio()) {
        return 0;
    } else {
        return 1 + max(nodo->iz->Altura(), nodo->de->Altura());
    }
}

int TABBCom::Nodos() const {
   if (EsVacio()) {
        return 0;
    } else {
        return 1 + nodo->iz->Nodos() + nodo->de->Nodos();
    }
}

int TABBCom::NodosHoja() const {
    if (EsVacio()) {
        return 0;
    } else if (nodo->iz->EsVacio() && nodo->de->EsVacio()) {
        return 1;
    } else {
        return nodo->iz->NodosHoja() + nodo->de->NodosHoja();
    }
}

TVectorCom TABBCom::Inorden() const {
    TVectorCom v(Nodos());
    int posicion = 1;
    InordenAux(v, posicion);
    return v;
}

TVectorCom TABBCom::Preorden() const {
    TVectorCom v(Nodos());
    int posicion = 1;
    PreordenAux(v, posicion);
    return v;
}

TVectorCom TABBCom::Postorden() const {
    TVectorCom v(Nodos());
    int posicion = 1;
    PostordenAux(v, posicion);
    return v;
}

TVectorCom TABBCom::Niveles() const {
    TVectorCom v(Nodos());
    int posicion = 1;
    NivelesAux(v, posicion);
    return v;
}

void TABBCom::InordenAux(TVectorCom& v, int& posicion) const {
    if (!EsVacio()) {
        nodo->iz->InordenAux(v, posicion);
        v[posicion++] = nodo->item;
        nodo->de->InordenAux(v, posicion);
    }
}

void TABBCom::PreordenAux(TVectorCom& v, int& posicion) const {
    if (!EsVacio()) {
        v[posicion++] = nodo->item;
        nodo->iz->PreordenAux(v, posicion);
        nodo->de->PreordenAux(v, posicion);
    }
}

void TABBCom::PostordenAux(TVectorCom& v, int& posicion) const {
    if (!EsVacio()) {
        nodo->iz->PostordenAux(v, posicion);
        nodo->de->PostordenAux(v, posicion);
        v[posicion++] = nodo->item;
    }
}

void TABBCom::NivelesAux(TVectorCom& v, int& posicion) const {
    if (!EsVacio()) {
        TVectorCom cola(Nodos());
        int frente = 1;
        int fin = 1;
        cola[fin] = nodo;
        while (frente <= fin) {
            TNodoABB* actual = cola[frente++];
            v[posicion++] = actual->item;
            if (actual->iz != nullptr) {
                cola[++fin] = actual->iz;
            }
            if (actual->de != nullptr) {
                cola[++fin] = actual->de;
            }
        }
    }
}

ostream& operator<<(ostream& os, const TABBCom& abb) {
    os << abb.Inorden();
    return os;
}
