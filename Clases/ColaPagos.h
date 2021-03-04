#ifndef COLAPAGOS_H
#define COLAPAGOS_H
#include "PagosNodo.h"
#include "Cliente.h"
class ColaPagos
{
public:
    ColaPagos();
    void push(PagosNodo *&, PagosNodo *&, Cliente *);
    Cliente *pop(PagosNodo *&, PagosNodo *&);
    void mostrarDatos(PagosNodo *);
    void crearCola(int, int, PagosNodo *&, PagosNodo *&,int);
    bool isColaVacia(PagosNodo *);
    bool yaExisteCliente(PagosNodo *&, int);
    bool yaExisteCarreta(PagosNodo *&,int);
    int obtenerMayor(PagosNodo *);
};

#endif /* COLAPAGOS _H */