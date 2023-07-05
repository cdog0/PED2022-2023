//
// Created by carlo on 13/06/2023.
//

#ifndef PED_TVECTORCOM_H
#define PED_TVECTORCOM_H
#include "../include/tcomplejo.h"

class TVectorCom {
private:
    TComplejo *c;
    int tamano;

public:
    // Constructores
    TVectorCom();
    TVectorCom(int);
    TVectorCom(TVectorCom&);

    // Destructor
    ~TVectorCom();

    // Sobrecarga de operadores
    TVectorCom& operator=(TVectorCom&);
    bool operator==(TVectorCom&);
    bool operator!=(TVectorCom&);
    TComplejo& operator[](int);
    TComplejo operator[](int) const;

    // Métodos
    int Tamano();
    int Ocupadas();
    bool ExisteCom(const TComplejo&);
    void MostrarComplejos(double);
    bool Redimensionar(int);

    // Funciones amigas
    friend ostream& operator<<(ostream&, TVectorCom&);
};

#endif

