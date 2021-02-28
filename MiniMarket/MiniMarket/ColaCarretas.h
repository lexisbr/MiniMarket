#ifndef COLACARRETAS_H
#define COLACARRETAS_H
#include "ColaClienteCarretas.h"
#include "Cliente.h"
class ColaCarretas {
public:
	ColaCarretas();
	void pushColaCarretas(ColaClienteCarretas*&, ColaClienteCarretas*&, Cliente*);
	bool isColaVacia(ColaClienteCarretas*);
	void crearColaCarretas(int, ColaClienteCarretas*&, ColaClienteCarretas*&);
	Cliente* popColaCarretas(ColaClienteCarretas*&, ColaClienteCarretas*&);
	void mostrarColaCarretas(ColaClienteCarretas*);

};
#endif // ! COLACARRETAS_H


