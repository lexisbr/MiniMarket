#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Cliente.h"
#include "ColaClienteCarretas.h"
using namespace std;
typedef Cliente* ClienteNodo;
typedef ColaClienteCarretas* ColaClienteNodo_1;

//Prototipos de funcion
void insertarCola(ColaClienteNodo_1&, ColaClienteNodo_1&, ClienteNodo);
bool isColaVacia(ColaClienteNodo_1);



int main() {
    ColaClienteNodo_1 frente = NULL;
    ColaClienteNodo_1 fin = NULL;
    int cantidad_clientes;

    cout << "=====================" << endl;
    cout << "|<>| MINI MARKET |<>|" << endl;
    cout << "=====================" << endl;
    cout << "Ingrese la cantidad de clientes: ";
    cin >> cantidad_clientes;

    for (int i = 1; i <= cantidad_clientes; i++)
    {
        ClienteNodo nuevo_cliente = new Cliente(i);
        
        insertarCola(frente, fin, nuevo_cliente);
    }

    _getch();
    return 0;
}


//Funcion para insertar un nuevo cliente a la cola de carretas
void insertarCola(ColaClienteNodo_1& frente, ColaClienteNodo_1& fin, ClienteNodo cliente) {
    ColaClienteNodo_1 nuevo_nodo = new ColaClienteCarretas(cliente);
    nuevo_nodo->setClienteSig(NULL);

    if (isColaVacia(frente)) {
        frente = new ColaClienteCarretas(cliente);
    }
    else {
        fin->setClienteSig(cliente);
    }

    fin = new ColaClienteCarretas(cliente);

    cout << "Cliente " << cliente->getCodigo() << " insertado a cola correctamente." << endl;
   
}

//Funcion para saber si la cola de clientes para carretas esta vacia
bool isColaVacia(ColaClienteNodo_1 frente) {
    return (frente == NULL) ? true : false;
}