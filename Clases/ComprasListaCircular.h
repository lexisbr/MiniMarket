#ifndef COMPRASLISTACIRCULAR_H
#define COMPRASLISTACIRCULAR_H
#include "ComprasNodo.h"
#include "Cliente.h"
class ComprasListaCircular{
    public:
        ComprasListaCircular();
        void addCliente(ComprasNodo*&,ComprasNodo*& ,Cliente*);
        void popCliente(ComprasNodo*&,ComprasNodo*&);
        bool isColaVacia(ComprasNodo*);

};

#endif /* COMPRASLISTACIRCULAR_H */