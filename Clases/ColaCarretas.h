#ifndef COLACARRETAS_H
#define COLACARRETAS_H
#include "ColaClienteCarretas.h"
#include "Cliente.h"
class ColaCarretas {
public:
	ColaCarretas();
	void pushColaCarretas(ColaClienteCarretas*&, ColaClienteCarretas*&, Cliente*);
	bool isColaVacia(ColaClienteCarretas*);
	bool yaExisteCliente(ColaClienteCarretas*&,int);
	void crearColaCarretas(int, ColaClienteCarretas*&, ColaClienteCarretas*&);
	void agregarClientes(int, ColaClienteCarretas*&, ColaClienteCarretas*&);
	Cliente* popColaCarretas(ColaClienteCarretas*&, ColaClienteCarretas*&);
	void mostrarColaCarretas(ColaClienteCarretas*);
	int cantidadItems(ColaClienteCarretas*&);
};
#endif // ! COLACARRETAS_H


