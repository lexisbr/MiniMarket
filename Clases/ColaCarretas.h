#ifndef COLACARRETAS_H
#define COLACARRETAS_H
#include "ColaClienteCarretas.h"
#include "Cliente.h"
#include "ComprasNodo.h"
#include "PagosNodo.h"
class ColaCarretas {
public:
	ColaCarretas();
	void pushColaCarretas(ColaClienteCarretas*&, ColaClienteCarretas*&, Cliente*);
	bool isColaVacia(ColaClienteCarretas*);
	bool yaExisteCliente(ColaClienteCarretas*&,int);
	void crearColaCarretas(int, ColaClienteCarretas*&, ColaClienteCarretas*&);
	void agregarClientes(int, ColaClienteCarretas*&, ColaClienteCarretas*&,ComprasNodo *&,ComprasNodo *&,PagosNodo *);
	Cliente* popColaCarretas(ColaClienteCarretas*&, ColaClienteCarretas*&);
	void mostrarColaCarretas(ColaClienteCarretas*);
	int obtenerMayor(ColaClienteCarretas*&);
};
#endif // ! COLACARRETAS_H


