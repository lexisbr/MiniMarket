#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "CajaNodo.h"
class ListaCajas{
    public:
    ListaCajas();
    void add(CajaNodo *&,CajaNodo *&,Caja *);
    void show(CajaNodo *);
    void crearCajas(CajaNodo *&,CajaNodo *&,int);



};

#endif 