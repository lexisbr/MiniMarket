#ifndef PILA_H
#define PILA_H
#include "CarretaNodo.h"
#include "Carreta.h"
class Pila
{
public:
	Pila();
	void pushPilaCarretas(CarretaNodo *&, Carreta *,int);
	void crearPilasCarretas(CarretaNodo *&, CarretaNodo *&, int, int);
	Carreta *popCarretaPila(CarretaNodo *&);
	void mostrarPilaCarretas(CarretaNodo *&, int);
	bool isCantidadCarretasPar(int);
	bool yaExisteCarreta(CarretaNodo *&, int);
};
#endif // !PILA_H
