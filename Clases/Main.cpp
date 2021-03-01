#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Cliente.h"
#include "ColaClienteCarretas.h"
#include "CarretaNodo.h"
#include "Pila.h"
#include "ColaCarretas.h"
#include "ComprasNodo.h"
#include "ComprasListaCircular.h"

using namespace std;
typedef Cliente* ClienteNodo;
typedef ColaClienteCarretas* ColaCarretasNodo;
typedef CarretaNodo* PilaCarretasNodo;
typedef ComprasNodo* ListaComprasNodo;

//Estructuras de datos
ColaCarretas colaCarretas;
Pila pila; 
ComprasListaCircular listaCompras;

//Prototipos
Cliente* asignarCarretaCliente(PilaCarretasNodo&,PilaCarretasNodo&,ColaCarretasNodo&,ColaCarretasNodo&);

int main() {
    PilaCarretasNodo pilaCarretas_1 = NULL;
    PilaCarretasNodo pilaCarretas_2 = NULL;

    ColaCarretasNodo frente_colaCarretas = NULL;
    ColaCarretasNodo fin_colaCarretas = NULL;

    ListaComprasNodo frente_listaCompra = NULL;
    ListaComprasNodo fin_listaCompra = NULL;

    int cantidad_clientes;
    int cantidad_carretas;
    int cantidad_caja;


    cout << "=====================" << endl;
    cout << "|<>| MINI MARKET |<>|" << endl;
    cout << "=====================" << endl;
    cout << "Ingrese la cantidad de carretas: ";
    cin >> cantidad_carretas;
    cout << "Ingrese la cantidad de clientes: ";
    cin >> cantidad_clientes;
    cout << "Ingrese la cantidad de cajas: ";
    cin >> cantidad_caja;
   
  

    cout << "=====================" << endl;
    cout << "|<>|   Paso #1  |<>|" << endl;
    cout << "=====================" << endl;
    pila.crearPilasCarretas(pilaCarretas_1,pilaCarretas_2,cantidad_carretas);

    cout << "=====================" << endl;
    cout << "|<>|   Paso #2  |<>|" << endl;
    cout << "=====================" << endl;
    colaCarretas.crearColaCarretas(cantidad_clientes, frente_colaCarretas, fin_colaCarretas);
  
   

    int opcion=1;
    int cont = 3;
    
    while (opcion == 1) {
        cout << "=====================" << endl;
        cout << "|<>|   Paso #"<<cont++<<"  |<>|" << endl;
        cout << "=====================" << endl;
        if (!colaCarretas.isColaVacia(frente_colaCarretas)) {
            Cliente* cliente = asignarCarretaCliente(pilaCarretas_1, pilaCarretas_2, frente_colaCarretas, fin_colaCarretas);
            listaCompras.addCliente(frente_listaCompra,fin_listaCompra,cliente);
        }
        else {
            cout << "No hay clientes esperando carreta. " << endl;
        }
       
        cout << "\n\tIngrese 1 para continuar o cualquier otra numero para salir: ";
        cin >> opcion;
    }
    _getch();
    return 0;
}


Cliente* asignarCarretaCliente(PilaCarretasNodo& pilaCarretas_1, PilaCarretasNodo& pilaCarretas_2, ColaCarretasNodo& frente_colaCarretas,ColaCarretasNodo& fin_colaCarretas) {
    Cliente* cliente = NULL;
    Carreta* carreta = NULL;

    if (pilaCarretas_1 != NULL || pilaCarretas_2 != NULL) {
        if (pilaCarretas_1 != NULL) {
            carreta = pila.popCarretaPila(pilaCarretas_1);
        }
        else{
            carreta = pila.popCarretaPila(pilaCarretas_2);
        }
        cliente = colaCarretas.popColaCarretas(frente_colaCarretas, fin_colaCarretas);
        cliente->setCarreta(carreta);
        cout << "Cliente: " << cliente->getCodigo() << " obtuvo carreta: " << cliente->getCarreta()->getCodigo() << endl;
       
    }
    else {
        cout << "No hay carretas disponibles." << endl;
    }
        return cliente;
}


