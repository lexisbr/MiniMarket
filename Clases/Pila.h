#ifndef PILA_H
#define PILA_H
#include "CarretaNodo.h"
#include "Carreta.h"
class Pila {
public:
	Pila();
	void pushPilaCarretas(CarretaNodo*&, Carreta*);
	void crearPilasCarretas(CarretaNodo*&, CarretaNodo*&, int);
	Carreta* popCarretaPila(CarretaNodo*&);
	void mostrarPilaCarretas(CarretaNodo*&);
	bool isCantidadCarretasPar(int);
};
#endif // !PILA_H

