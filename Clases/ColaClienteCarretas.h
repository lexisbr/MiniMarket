#ifndef COLACLIENTECARRETAS_H
#define COLACLIENTECARRETAS_H
#include "Cliente.h"
class ColaClienteCarretas
{
private:
	Cliente *cliente;
	ColaClienteCarretas *cliente_sig;

public:
	ColaClienteCarretas(Cliente *);
	void setClienteSig(ColaClienteCarretas *);
	void setCliente(Cliente *);
	Cliente *getCliente();
	ColaClienteCarretas *getClienteSig();
};

#endif // !COLACLIENTECARRETAS_H
