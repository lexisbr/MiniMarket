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
#include "PagosNodo.h"
#include "ColaPagos.h"
#include "ListaCajas.h"
#include "CajaNodo.h"
#include <time.h>

using namespace std;
typedef Cliente *ClienteNodo;
typedef ColaClienteCarretas *ColaCarretasNodo;
typedef CarretaNodo *PilaCarretasNodo;
typedef ComprasNodo *ListaComprasNodo;
typedef PagosNodo *_PagosNodo;
typedef CajaNodo *_CajaNodo;

//Estructuras de datos
ColaCarretas colaCarretas;
Pila pila;
ComprasListaCircular listaCompras;
ColaPagos colaPagos;
ListaCajas listaCajas;

//Prototipos
Cliente *asignarCarretaCliente(PilaCarretasNodo &, PilaCarretasNodo &, ColaCarretasNodo &, ColaCarretasNodo &);
void regresarCarreta(Carreta *, PilaCarretasNodo &, PilaCarretasNodo &);

int main()
{
    srand(time(NULL));
    PilaCarretasNodo pilaCarretas_1 = NULL;
    PilaCarretasNodo pilaCarretas_2 = NULL;

    ColaCarretasNodo frente_colaCarretas = NULL;
    ColaCarretasNodo fin_colaCarretas = NULL;

    ListaComprasNodo frente_listaCompra = NULL;
    ListaComprasNodo fin_listaCompra = NULL;

    _PagosNodo frente_colaPagos = NULL;
    _PagosNodo fin_colaPagos = NULL;

    _CajaNodo frente_listaCajas = NULL;
    _CajaNodo fin_listaCajas = NULL;

    int cantidad_clientes_carretas;
    int cantidad_clientes_compras;
    int cantidad_carretas1;
    int cantidad_carretas2;
    int cantidad_clientes_pagos;
    int cantidad_cajas;

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
    cout << "Ingrese la cantidad de clientes en cola para pagar: ";
    cin >> cantidad_clientes_pagos;
    cout << "Ingrese la cantidad de cajas: ";
    cin >> cantidad_cajas;

    cout << "=====================" << endl;
    cout << "|<>|   Paso #1  |<>|" << endl;
    cout << "=====================" << endl;
    colaCarretas.crearColaCarretas(cantidad_clientes_carretas, frente_colaCarretas, fin_colaCarretas);
    colaCarretas.mostrarColaCarretas(frente_colaCarretas);
    pila.crearPilasCarretas(pilaCarretas_1, pilaCarretas_2, cantidad_carretas1, cantidad_carretas2);
    pila.mostrarPilaCarretas(pilaCarretas_1, 1);
    pila.mostrarPilaCarretas(pilaCarretas_2, 2);
    int total_carretas = cantidad_carretas1 + cantidad_carretas2;
    listaCompras.crearListaCompras(frente_listaCompra, fin_listaCompra, cantidad_clientes_compras, cantidad_clientes_carretas, total_carretas);
    listaCompras.mostrarDatos(frente_listaCompra, fin_listaCompra);
    int total_clientes = cantidad_clientes_carretas + cantidad_clientes_compras;
    total_carretas = total_carretas + cantidad_clientes_compras;
    colaPagos.crearCola(cantidad_clientes_pagos, total_clientes, frente_colaPagos, fin_colaPagos, total_carretas);
    colaPagos.mostrarDatos(frente_colaPagos);

    listaCajas.crearCajas(frente_listaCajas, fin_listaCajas, cantidad_cajas);
    listaCajas.show(frente_listaCajas);
    _getch();

    int cont = 2;
    int cantidad_clientes_nuevos = 0;
    bool final = true;

    while (final)
    {
        cout << "=====================" << endl;
        cout << "|<>|   Paso #" << cont++ << "  |<>|" << endl;
        cout << "=====================" << endl;
        if (cantidad_clientes_nuevos > 0)
            colaCarretas.agregarClientes(cantidad_clientes_nuevos, frente_colaCarretas, fin_colaCarretas, frente_listaCompra, fin_listaCompra, frente_colaPagos);

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
        if (!listaCompras.isColaVacia(frente_listaCompra))
        {
            Cliente *cliente = listaCompras.popCliente(frente_listaCompra, fin_listaCompra);
            if (cliente != NULL)
            {
                colaPagos.push(frente_colaPagos, fin_colaPagos, cliente);
            }
        }
        listaCompras.mostrarDatos(frente_listaCompra, fin_listaCompra);

        if (frente_colaPagos != NULL && listaCajas.hayCajasDisponibles(frente_listaCajas))
        {
            Cliente *cliente = colaPagos.pop(frente_colaPagos, fin_colaPagos);
            listaCajas.addCliente(frente_listaCajas, cliente);
        }
        colaPagos.mostrarDatos(frente_colaPagos);
        listaCajas.show(frente_listaCajas);

        Carreta *carreta_regreso = NULL;
        do
        {
            carreta_regreso = listaCajas.popCliente(frente_listaCajas);
            if (carreta_regreso != NULL)
            {
                regresarCarreta(carreta_regreso, pilaCarretas_1, pilaCarretas_2);
            }
        } while (carreta_regreso != NULL);

        listaCajas.incrementContadores(frente_listaCajas);
        /**/

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
        cout << "-- Cliente: " << cliente->getCodigo() << " obtuvo carreta: " << cliente->getCarreta()->getCodigo() << endl;
    }

    return cliente;
}

void regresarCarreta(Carreta *carreta, PilaCarretasNodo &pilaCarretas_1, PilaCarretasNodo &pilaCarretas_2)
{
    int pila_random = 0;
    pila_random = (rand() % 2);
    if (pila_random == 0)
    {
        pila.pushPilaCarretas(pilaCarretas_1, carreta, 1);
    }
    else
    {
        pila.pushPilaCarretas(pilaCarretas_2, carreta, 2);
    }
}