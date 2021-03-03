#ifndef COMPRASLISTACIRCULAR_H
#define COMPRASLISTACIRCULAR_H
#include "ComprasNodo.h"
#include "Cliente.h"
class ComprasListaCircular
{
public:
    ComprasListaCircular();
    void addCliente(ComprasNodo *&, ComprasNodo *&, Cliente *);
    Cliente *popCliente(ComprasNodo *&, ComprasNodo *&);
    void mostrarDatos(ComprasNodo *&, ComprasNodo *&);
    bool isColaVacia(ComprasNodo *);
    void crearListaCompras(ComprasNodo *&, ComprasNodo *&, int, int, int);
    bool yaExisteCliente(ComprasNodo *&, ComprasNodo *&, int);
    bool yaExisteCarreta(ComprasNodo *&, ComprasNodo *&, int);
    int obtenerMayor(ComprasNodo *&, ComprasNodo *&);
};

#endif /* COMPRASLISTACIRCULAR_H */