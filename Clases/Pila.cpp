#include <iostream>
#include <string>
#include "Pila.h"
#include "Carreta.h"
#include "CarretaNodo.h"
using namespace std;

Pila::Pila() {
}

void Pila::pushPilaCarretas(CarretaNodo*& pila, Carreta* carreta) {
	CarretaNodo* nuevo_nodo = new CarretaNodo(carreta);
	nuevo_nodo->setCarretaSig(pila);
	pila = nuevo_nodo;
	if (pila->getCarretaSig() != NULL)
		cout << "Carreta: " << pila->getCarreta()->getCodigo() << " introducida a pila, carreta siguiente: " << pila->getCarretaSig()->getCarreta()->getCodigo()<<"."<< endl;
	else
		cout << "Carreta: " << pila->getCarreta()->getCodigo() << " introducida a pila." << endl;
}

void Pila::crearPilasCarretas(CarretaNodo*& pila_1, CarretaNodo*& pila_2, int cantidad_carretas) {

	int diferencia = 0;
	if (!isCantidadCarretasPar(cantidad_carretas))
		diferencia++;

	int mitad_carretas = diferencia+(cantidad_carretas / 2);
	for (int i = 1; i <= mitad_carretas; i++)
	{
		Carreta* carreta = new Carreta(i);
		pushPilaCarretas(pila_1, carreta);
	}
	for (int i = (mitad_carretas + 1); i <= cantidad_carretas; i++)
	{
		Carreta* carreta = new Carreta(i);
		pushPilaCarretas(pila_2, carreta);
	}
		
}

Carreta* Pila::popCarretaPila(CarretaNodo*& pila) {
	CarretaNodo* aux = pila;
	Carreta* carreta = aux->getCarreta();
	pila = aux->getCarretaSig();
	delete aux;
	return carreta;
}

void Pila::mostrarPilaCarretas(CarretaNodo*& pila) {
	CarretaNodo* aux = pila;
	while (aux != NULL) {
		Carreta* carreta = aux->getCarreta();
		aux = aux->getCarretaSig();
		cout << "Carreta: " << carreta->getCodigo() << endl;
	}
}

bool Pila::isCantidadCarretasPar(int cantidad_carretas) {
	return (cantidad_carretas % 2 == 0) ? true : false;
}