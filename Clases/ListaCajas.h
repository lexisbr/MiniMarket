#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "CajaNodo.h"
#include "Caja.h"
#include "Carreta.h"
class ListaCajas{
    public:
    ListaCajas();
    void add(CajaNodo *&,CajaNodo *&,Caja *);
    void show(CajaNodo *);
    void crearCajas(CajaNodo *&,CajaNodo *&,int);
    bool hayCajasDisponibles(CajaNodo *);
    void addCliente(CajaNodo *&,Cliente*);
    void incrementContadores(CajaNodo *&);
    Carreta* popCliente(CajaNodo *&);

};

#endif 