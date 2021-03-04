#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "ListaCajas.h"
#include "CajaNodo.h"
#include "Caja.h"
#include "Carreta.h"
using namespace std;

ListaCajas::ListaCajas() {}

void ListaCajas::add(CajaNodo *&frente, CajaNodo *&fin, Caja *caja)
{
    CajaNodo *nuevo_nodo = new CajaNodo(caja);
    nuevo_nodo->setCajaSig(NULL);
    nuevo_nodo->setCajaAnt(NULL);

    if (frente == NULL)
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin->setCajaSig(nuevo_nodo);
        nuevo_nodo->setCajaAnt(fin);
    }
    fin = nuevo_nodo;
}

void ListaCajas::show(CajaNodo *frente)
{
    CajaNodo *aux = frente;
    while (aux != NULL)
    {
        CajaNodo *caja = aux;
        aux = aux->getCajaSig();
        if (caja->getCaja()->isEstaLibre())
        {
            cout << "\t\t\t\t\t** Caja: " << caja->getCaja()->getNumeroCaja() << " esta disponible. Tiempo de espera: " << caja->getCaja()->getTiempoServicio() << " Tiempo que lleva: " << caja->getCaja()->getContadorPasos() << endl;
        }
        else
        {
            cout << "\t\t\t\t\t** Caja: " << caja->getCaja()->getNumeroCaja() << " esta atendiendo a cliente " << caja->getCaja()->getCliente()->getCodigo() << " Tiempo de espera: " << caja->getCaja()->getTiempoServicio() << " Tiempo que lleva: " << caja->getCaja()->getContadorPasos() << endl;
        }
    }
}

void ListaCajas::crearCajas(CajaNodo *&frente, CajaNodo *&fin, int cantidad_cajas)
{
    if (cantidad_cajas > 0)
    {
        for (int i = 1; i <= cantidad_cajas; i++)
        {
            int tiempo_espera = (rand() % 10) + 1;
            Caja *nueva_caja = new Caja(i, tiempo_espera, true);
            add(frente, fin, nueva_caja);
        }
    }
}

bool ListaCajas::hayCajasDisponibles(CajaNodo *frente)
{
    CajaNodo *aux = frente;

    while (aux != NULL)
    {
        Caja *caja = aux->getCaja();
        aux = aux->getCajaSig();
        if (caja->isEstaLibre())
        {
            return true;
        }
    }
    return false;
}

void ListaCajas::addCliente(CajaNodo *&frente, Cliente *cliente)
{
    CajaNodo *aux = frente;

    while (aux != NULL)
    {
        if (aux->getCaja()->isEstaLibre())
        {
            cout << "\t\t\t\t@@ Cliente: " << cliente->getCodigo() << "  entra a Caja: " << aux->getCaja()->getNumeroCaja() << "." << endl;
            aux->getCaja()->setCliente(cliente);
            aux->getCaja()->setEstaLibre(false);
            aux = NULL;
        }
        else
        {
            aux = aux->getCajaSig();
        }
    }
}

void ListaCajas::incrementContadores(CajaNodo *&frente)
{
    CajaNodo *aux = frente;

    while (aux != NULL)
    {
        if (!aux->getCaja()->isEstaLibre())
        {
            aux->getCaja()->incrementContadorPasos();
        }
        aux = aux->getCajaSig();
    }
}

Carreta *ListaCajas::popCliente(CajaNodo *&frente)
{
    CajaNodo *aux = frente;
    Carreta *carreta = NULL;
    while (aux != NULL)
    {
        if (!aux->getCaja()->isEstaLibre())
        {
            if (aux->getCaja()->getTiempoServicio() == aux->getCaja()->getContadorPasos())
            {
                carreta = aux->getCaja()->getCliente()->getCarreta();
                cout << "\n\t\t\t\t\t\t--> Cliente: " << aux->getCaja()->getCliente()->getCodigo() << "  sale de Caja: " << aux->getCaja()->getNumeroCaja() << " deja Carreta: " << carreta->getCodigo() << ".\n" << endl;
                Caja *nueva_caja = new Caja(aux->getCaja()->getNumeroCaja(),aux->getCaja()->getTiempoServicio(),true);
                delete aux->getCaja();

                aux->setCaja(nueva_caja);
                return carreta;
            }
            else
            {
                aux = aux->getCajaSig();
            }
        }
        else
        {
            aux = aux->getCajaSig();
        }
    }

    return carreta;
}
