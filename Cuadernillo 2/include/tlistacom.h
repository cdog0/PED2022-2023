#ifndef TLISTACOM_H
#define TLISTACOM_H

#include "tlistanodo.h"
#include "tlistapos.h"
#include "tcomplejo.h"

class TListaCom {
private:
    TListaNodo* primero;
    TListaNodo* ultimo;

public:
    TListaCom();
    TListaCom(const TListaCom& otro);
    ~TListaCom();
    TListaCom& operator=(const TListaCom& otro);
    bool operator==(const TListaCom& otro);
    bool operator!=(const TListaCom& otro);
    TListaPos Primera() const;
    TListaPos Ultima();
    bool EsVacia();
    bool InsCabeza(TComplejo& complejo);
    bool InsertarI(TComplejo& complejo, TListaPos& pos);
    bool InsertarD(TComplejo& complejo, TListaPos& pos);
    bool Borrar(TComplejo& complejo);
    bool BorrarTodos(TComplejo& complejo);
    bool Borrar(TListaPos& pos);
    TComplejo Obtener(TListaPos& pos) const;
    bool Buscar(TComplejo& complejo);
    int Longitud();

    friend std::ostream& operator<<(std::ostream& os, TListaCom& lista);
};

#endif
