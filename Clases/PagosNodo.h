#ifndef PAGOSNODO_H
#define PAGOSNODO_H
#include "Cliente.h"
class PagosNodo
{
private:
    Cliente *cliente;
    PagosNodo *cliente_sig;

public:
    PagosNodo(Cliente *);
    void setCliente(Cliente *);
    void setClienteSig(PagosNodo *);
    Cliente *getCliente();
    PagosNodo *getClienteSig();
};

#endif /* PAGOSNODO_H */