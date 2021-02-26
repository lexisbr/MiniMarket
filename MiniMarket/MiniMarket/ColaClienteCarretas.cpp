#include<iostream>
#include "ColaClienteCarretas.h"
#include "Cliente.h"

ColaClienteCarretas::ColaClienteCarretas(Cliente* cliente) {
	this->cliente = cliente;
}

void ColaClienteCarretas::setClienteSig(Cliente* cliente_sig) {
	this->cliente_sig = cliente_sig;
}

void ColaClienteCarretas::setCliente(Cliente* cliente) {
	this->cliente = cliente;
}