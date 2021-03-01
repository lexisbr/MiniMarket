#include<iostream>
#include "ColaClienteCarretas.h"
#include "Cliente.h"

ColaClienteCarretas::ColaClienteCarretas(Cliente* cliente) {
	this->cliente = cliente;
}

void ColaClienteCarretas::setClienteSig(ColaClienteCarretas* cliente_sig) {
	this->cliente_sig = cliente_sig;
}

void ColaClienteCarretas::setCliente(Cliente* cliente) {
	this->cliente = cliente;
}

Cliente* ColaClienteCarretas::getCliente() {
	return cliente;
}

ColaClienteCarretas* ColaClienteCarretas::getClienteSig() {
	return cliente_sig;
}