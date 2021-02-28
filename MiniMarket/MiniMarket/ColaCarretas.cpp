#include <iostream>
#include "ColaCarretas.h"
#include "Cliente.h"
#include "ColaClienteCarretas.h"
using namespace std;

ColaCarretas::ColaCarretas() {

}

//Crear cola de clientes para las carretas
void ColaCarretas::crearColaCarretas(int cantidad_clientes, ColaClienteCarretas*& frente, ColaClienteCarretas*& fin) {

    for (int i = 1; i <= cantidad_clientes; i++)
    {
        Cliente* nuevo_cliente = new Cliente(i);
        pushColaCarretas(frente, fin, nuevo_cliente);
    }
}

//Funcion para insertar un nuevo cliente a la cola de carretas
void ColaCarretas::pushColaCarretas(ColaClienteCarretas*& frente, ColaClienteCarretas*& fin, Cliente* cliente) {
    ColaClienteCarretas* nuevo_nodo = new ColaClienteCarretas(cliente);
    nuevo_nodo->setClienteSig(NULL);

    if (isColaVacia(frente)) {
        frente = nuevo_nodo;
    }
    else {
        fin->setClienteSig(nuevo_nodo);
    }

    fin = nuevo_nodo;

    cout << "Cliente " << nuevo_nodo->getCliente()->getCodigo() << " ingresa a cola para adquirir carreta." << endl;

}

//Funcion para saber si la cola de clientes para carretas esta vacia
bool ColaCarretas::isColaVacia(ColaClienteCarretas* frente) {
    return (frente == NULL) ? true : false;
}



// Desencolar el primer elemento insertado 
Cliente* ColaCarretas::popColaCarretas(ColaClienteCarretas*& frente, ColaClienteCarretas*& fin) {
    ColaClienteCarretas* aux = frente;

    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    }
    else {
        frente = frente->getClienteSig();
    }

    Cliente* cliente = aux->getCliente();
    cout << "Cliente: " << cliente->getCodigo()<<" sale de cola para tomar una carreta."<< endl;

 
    delete aux;

    return cliente;

}

void ColaCarretas::mostrarColaCarretas(ColaClienteCarretas* frente) {
    ColaClienteCarretas* aux = frente;
    Cliente* cliente = NULL;
    while (aux != NULL) {
        cliente = aux->getCliente();
        aux = aux->getClienteSig();
        cout << "Cliente: " << cliente->getCodigo() << endl;

    }
}