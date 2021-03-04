#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include "Pila.h"
#include "Carreta.h"
#include "CarretaNodo.h"
using namespace std;

Pila::Pila()
{
}

void Pila::pushPilaCarretas(CarretaNodo *&pila, Carreta *carreta, int num_pila)
{
	CarretaNodo *nuevo_nodo = new CarretaNodo(carreta);
	nuevo_nodo->setCarretaSig(pila);
	pila = nuevo_nodo;
	//cout << "\t++ Carreta: " << pila->getCarreta()->getCodigo() << " introducida a pila: " << num_pila << "." << endl;
}

void Pila::crearPilasCarretas(CarretaNodo *&pila1, CarretaNodo *&pila2, int cantidad_carretas1, int cantidad_carretas2)
{
	int id = 0;
	if (cantidad_carretas1 > 0)
	{
		id = (rand() % cantidad_carretas1) + 1;
		for (int i = 0; i < cantidad_carretas1; i++)
		{
			while (yaExisteCarreta(pila1, id))
			{
				id = rand() % cantidad_carretas1 + 1;
			}
			Carreta *carreta = new Carreta(id);
			pushPilaCarretas(pila1, carreta, 1);
		}
	}

	if (cantidad_carretas2 > 0)
	{
		id = (rand() % cantidad_carretas2) + (cantidad_carretas1 + 1);

		for (int i = 0; i < cantidad_carretas2; i++)
		{
			while (yaExisteCarreta(pila2, id))
			{
				id = (rand() % cantidad_carretas2) + (cantidad_carretas1 + 1);
			}
			Carreta *carreta = new Carreta(id);
			pushPilaCarretas(pila2, carreta, 2);
		}
	}
}

bool Pila::yaExisteCarreta(CarretaNodo *&pila, int id)
{
	CarretaNodo *aux = pila;
	while (aux != NULL)
	{
		if (aux->getCarreta()->getCodigo() == id)
			return true;
		else
			aux = aux->getCarretaSig();
	}

	return false;
}

Carreta *Pila::popCarretaPila(CarretaNodo *&pila)
{
	CarretaNodo *aux = pila;
	Carreta *carreta = aux->getCarreta();
	pila = aux->getCarretaSig();
	delete aux;
	return carreta;
}

void Pila::mostrarPilaCarretas(CarretaNodo *&pila, int num_pila)
{
	CarretaNodo *aux = pila;
	if (aux != NULL)
	{
		while (aux != NULL)
		{
			Carreta *carreta = aux->getCarreta();
			aux = aux->getCarretaSig();
			cout << "\t++ Carreta: " << carreta->getCodigo() << " se encuentra disponible en pila: " << num_pila << "." << endl;
		}
	}
	else
	{
		cout << "\t++ No hay carretas disponibles en pila: " << num_pila << "." << endl;
	}
}
