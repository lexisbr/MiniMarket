#ifndef COMPRASLISTACIRCULAR_H
#define COMPRASLISTACIRCULAR_H
#include "ComprasNodo.h"
#include "Cliente.h"
class ComprasListaCircular{
    public:
        ComprasListaCircular();
        void addCliente(ComprasNodo*&,ComprasNodo*& ,Cliente*);
        Cliente* popCliente(ComprasNodo*&,ComprasNodo*&);
        void mostrarDatos(ComprasNodo*&,ComprasNodo*&);
        bool isColaVacia(ComprasNodo*);
        void crearListaCompras(ComprasNodo*&,ComprasNodo*&,int,int);
        bool yaExisteCliente(ComprasNodo*&,ComprasNodo*&,int);

};

#endif /* COMPRASLISTACIRCULAR_H */