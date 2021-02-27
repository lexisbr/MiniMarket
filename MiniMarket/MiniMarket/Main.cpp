#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Cliente.h"
#include "ColaClienteCarretas.h"
using namespace std;
typedef Cliente* ClienteNodo;
typedef ColaClienteCarretas* ColaClienteNodo_1;

//Prototipos de funcion
void pushColaCarretas(ColaClienteNodo_1&, ColaClienteNodo_1&, ClienteNodo);
bool isColaVacia(ColaClienteNodo_1);
void crearColaCarretas(int,ColaClienteNodo_1&,ColaClienteNodo_1&);
void popColaCarretas(ColaClienteNodo_1&, ColaClienteNodo_1&);
void mostrarColaCarretas(ColaClienteNodo_1);

int main() {
    ColaClienteNodo_1 frente = NULL;
    ColaClienteNodo_1 fin = NULL;
    int cantidad_clientes;

    cout << "=====================" << endl;
    cout << "|<>| MINI MARKET |<>|" << endl;
    cout << "=====================" << endl;
    cout << "Ingrese la cantidad de clientes: ";
    cin >> cantidad_clientes;
    crearColaCarretas(cantidad_clientes, frente, fin);

    

    mostrarColaCarretas(frente);
    popColaCarretas(frente, fin);
    mostrarColaCarretas(frente);
    popColaCarretas(frente, fin);
    mostrarColaCarretas(frente);


    _getch();
    return 0;
}


//Funcion para insertar un nuevo cliente a la cola de carretas
void pushColaCarretas(ColaClienteNodo_1& frente, ColaClienteNodo_1& fin, ClienteNodo cliente) {
    ColaClienteNodo_1 nuevo_nodo = new ColaClienteCarretas(cliente);
    nuevo_nodo->setClienteSig(NULL);

    if (isColaVacia(frente)) {
        frente = nuevo_nodo;
    }
    else {
        fin->setClienteSig(nuevo_nodo);
    }

    fin = nuevo_nodo;

    cout << "Cliente " << nuevo_nodo->getCliente()->getCodigo() << " insertado a cola correctamente." << endl;
   
}

//Funcion para saber si la cola de clientes para carretas esta vacia
bool isColaVacia(ColaClienteNodo_1 frente) {
    return (frente == NULL) ? true : false;
}

//Crear cola de clientes para las carretas
void crearColaCarretas(int cantidad_clientes, ColaClienteNodo_1& frente, ColaClienteNodo_1& fin){

    for (int i = 1; i <= cantidad_clientes; i++)
    {
        ClienteNodo nuevo_cliente = new Cliente(i);
        pushColaCarretas(frente, fin, nuevo_cliente);
    }
}

// Desencolar el primer elemento insertado 
void popColaCarretas(ColaClienteNodo_1& frente, ColaClienteNodo_1& fin) {
    ColaClienteNodo_1 aux = frente;

    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    }
    else {
        frente = frente->getClienteSig();
    }

    cout << "Se elimino Cliente: " << aux->getCliente()->getCodigo() << endl;

    delete aux;

}

void mostrarColaCarretas(ColaClienteNodo_1 frente) {
    ColaClienteNodo_1 aux = frente;
    ClienteNodo cliente = NULL;
    while (aux != NULL) {
        cliente = aux->getCliente();
        aux = aux->getClienteSig();
        cout << "Cliente: " << cliente->getCodigo() << endl;
       
    }
}