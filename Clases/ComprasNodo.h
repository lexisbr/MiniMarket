#ifndef COMPRASNODO_H
#define COMPRASNODO_H
#include "Cliente.h"
class ComprasNodo {
    private:
        Cliente* cliente;
        ComprasNodo* cliente_sig;
    public:
        ComprasNodo(Cliente*);
        void setClienteSig(ComprasNodo*);
        void setCliente(Cliente*);
        Cliente* getCliente();
        ComprasNodo*  getClienteSig();

};
#endif /* COMPRASNODO_H */