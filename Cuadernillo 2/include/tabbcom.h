#ifndef TABBCOM_H
#define TABBCOM_H

#include <iostream>
#include "tcomplejo.h"
#include "tnodoabb.h"
#include "tvectorcom.h"

using namespace std;

class TABBCom {
private:
    TNodoABB* nodo;

    void InordenAux(TVectorCom& v, int& posicion) const;
    void PreordenAux(TVectorCom& v, int& posicion) const;
    void PostordenAux(TVectorCom& v, int& posicion) const;
    void NivelesAux(TVectorCom& v, int& posicion) const;

public:
    TABBCom();
    TABBCom(const TABBCom& abb);
    ~TABBCom();
    TABBCom& operator=(const TABBCom& abb);

    bool operator==(const TABBCom& abb) const;

    bool EsVacio() const;
    bool Insertar(const TComplejo& complejo);
    bool Borrar(const TComplejo& complejo);
    bool Buscar(const TComplejo& complejo) const;

    TComplejo Raiz() const;
    int Altura() const;
    int Nodos() const;
    int NodosHoja() const;

    TVectorCom Inorden() const;
    TVectorCom Preorden() const;
    TVectorCom Postorden() const;
    TVectorCom Niveles() const;

    friend ostream& operator<<(ostream& os, const TABBCom& abb);
};

#endif  // TABBCOM_H
