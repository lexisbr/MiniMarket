#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Cliente.h"
#include "ColaClienteCarretas.h"
#include "CarretaNodo.h"
#include "Pila.h"
#include "ColaCarretas.h"

using namespace std;
typedef Cliente* ClienteNodo;
typedef ColaClienteCarretas* ColaCarretasNodo;
typedef CarretaNodo* PilaCarretasNodo;

//Estructuras de datos
ColaCarretas colaCarretas;
Pila pila; 

//Prototipos
void asignarCarretaCliente(PilaCarretasNodo&,PilaCarretasNodo&,ColaCarretasNodo&,ColaCarretasNodo&);

int main() {
    PilaCarretasNodo pilaCarretas_1 = NULL;
    PilaCarretasNodo pilaCarretas_2 = NULL;

    ColaCarretasNodo frente_colaCarretas = NULL;
    ColaCarretasNodo fin_colaCarretas = NULL;

    int cantidad_clientes;
    int cantidad_carretas;


    cout << "=====================" << endl;
    cout << "|<>| MINI MARKET |<>|" << endl;
    cout << "=====================" << endl;
    cout << "Ingrese la cantidad de carretas: ";
    cin >> cantidad_carretas;
    cout << "Ingrese la cantidad de clientes: ";
    cin >> cantidad_clientes;
   
  

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
            asignarCarretaCliente(pilaCarretas_1, pilaCarretas_2, frente_colaCarretas, fin_colaCarretas);
        }
        else {
            cout << "No hay clientes esperando carreta. " << endl;
        }
       
        cout << "\n\tIngrese 1 para continuar o cualquier otra numero para salir: ";
        cin >> opcion;
    }

    return 0;
}


void asignarCarretaCliente(PilaCarretasNodo& pilaCarretas_1, PilaCarretasNodo& pilaCarretas_2, ColaCarretasNodo& frente_colaCarretas,ColaCarretasNodo& fin_colaCarretas) {
    Carreta* carreta = NULL;

    if (pilaCarretas_1 != NULL || pilaCarretas_2 != NULL) {
        if (pilaCarretas_1 != NULL) {
            carreta = pila.popCarretaPila(pilaCarretas_1);
        }
        else{
            carreta = pila.popCarretaPila(pilaCarretas_2);
        }
        Cliente* cliente = colaCarretas.popColaCarretas(frente_colaCarretas, fin_colaCarretas);
        cliente->setCarreta(carreta);
        cout << "Cliente: " << cliente->getCodigo() << " obtuvo carreta: " << carreta->getCodigo() << endl;
    }
    else {
        cout << "No hay carretas disponibles." << endl;
    }

    

}


