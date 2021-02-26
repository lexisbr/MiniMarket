#ifndef COLACLIENTECARRETAS_H
#define COLACLIENTECARRETAS_H
#include "Cliente.h"
class ColaClienteCarretas {
private:
	Cliente* cliente;
	Cliente* cliente_sig;
public:
	ColaClienteCarretas(Cliente*);
	void setClienteSig(Cliente*);
	void setCliente(Cliente*);
};

#endif // !COLACLIENTECARRETAS_H

