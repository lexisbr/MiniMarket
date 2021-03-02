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
typedef Cliente *ClienteNodo;
typedef ColaClienteCarretas *ColaCarretasNodo;
typedef CarretaNodo *PilaCarretasNodo;
typedef ComprasNodo *ListaComprasNodo;

//Estructuras de datos
ColaCarretas colaCarretas;
Pila pila;
ComprasListaCircular listaCompras;

//Prototipos
Cliente *asignarCarretaCliente(PilaCarretasNodo &, PilaCarretasNodo &, ColaCarretasNodo &, ColaCarretasNodo &);

int main()
{
    PilaCarretasNodo pilaCarretas_1 = NULL;
    PilaCarretasNodo pilaCarretas_2 = NULL;

    ColaCarretasNodo frente_colaCarretas = NULL;
    ColaCarretasNodo fin_colaCarretas = NULL;

    ListaComprasNodo frente_listaCompra = NULL;
    ListaComprasNodo fin_listaCompra = NULL;

    int cantidad_clientes_carretas;
    int cantidad_clientes_compras;
    int cantidad_carretas1;
    int cantidad_carretas2;
    int cantidad_caja;

    cout << "=====================" << endl;
    cout << "|<>| MINI MARKET |<>|" << endl;
    cout << "=====================" << endl;
    cout << "Ingrese la cantidad de carretas en pila 1: ";
    cin >> cantidad_carretas1;
    cout << "Ingrese la cantidad de carretas en pila 2: ";
    cin >> cantidad_carretas2;
    cout << "Ingrese la cantidad de clientes en cola para carretas: ";
    cin >> cantidad_clientes_carretas;
    cout << "Ingrese la cantidad de clientes comprando: ";
    cin >> cantidad_clientes_compras;
    cout << "Ingrese la cantidad de cajas: ";
    cin >> cantidad_caja;

    cout << "=====================" << endl;
    cout << "|<>|   Paso #1  |<>|" << endl;
    cout << "=====================" << endl;
    colaCarretas.crearColaCarretas(cantidad_clientes_carretas, frente_colaCarretas, fin_colaCarretas);
    pila.crearPilasCarretas(pilaCarretas_1,pilaCarretas_2,cantidad_carretas1,cantidad_carretas2);
    pila.mostrarPilaCarretas(pilaCarretas_1,1);
    pila.mostrarPilaCarretas(pilaCarretas_2,2);
    listaCompras.crearListaCompras(frente_listaCompra,fin_listaCompra,cantidad_clientes_compras,cantidad_clientes_carretas);
    _getch();

    int cont = 2;
    int cantidad_clientes_nuevos=0;
    bool final=true;

    while (final)
    {
        cout << "=====================" << endl;
        cout << "|<>|   Paso #" << cont++ << "  |<>|" << endl;
        cout << "=====================" << endl;
        /*if(cantidad_clientes_nuevos>0)
        colaCarretas.crearColaCarretas(cantidad_clientes_nuevos, frente_colaCarretas, fin_colaCarretas);*/

        if (!colaCarretas.isColaVacia(frente_colaCarretas))
        {
            Cliente *cliente = asignarCarretaCliente(pilaCarretas_1, pilaCarretas_2, frente_colaCarretas, fin_colaCarretas);
            if (cliente != NULL)
            {
                listaCompras.addCliente(frente_listaCompra, fin_listaCompra, cliente);
            }
        }

        colaCarretas.mostrarColaCarretas(frente_colaCarretas);
        pila.mostrarPilaCarretas(pilaCarretas_1, 1);
        pila.mostrarPilaCarretas(pilaCarretas_2, 2);
        listaCompras.mostrarDatos(frente_listaCompra, fin_listaCompra);

        cout << "\n\tIngrese cantidad de clientes que entraran: ";
        cin >> cantidad_clientes_nuevos;

    }
    _getch();
    return 0;
}

Cliente *asignarCarretaCliente(PilaCarretasNodo &pilaCarretas_1, PilaCarretasNodo &pilaCarretas_2, ColaCarretasNodo &frente_colaCarretas, ColaCarretasNodo &fin_colaCarretas)
{
    Cliente *cliente = NULL;
    Carreta *carreta = NULL;

    if (pilaCarretas_1 != NULL || pilaCarretas_2 != NULL)
    {
        if (pilaCarretas_1 != NULL)
        {
            carreta = pila.popCarretaPila(pilaCarretas_1);
        }
        else
        {
            carreta = pila.popCarretaPila(pilaCarretas_2);
        }
        cliente = colaCarretas.popColaCarretas(frente_colaCarretas, fin_colaCarretas);
        cliente->setCarreta(carreta);
        cout << "** Cliente: " << cliente->getCodigo() << " obtuvo carreta: " << cliente->getCarreta()->getCodigo() << endl;
    }

    return cliente;
}
