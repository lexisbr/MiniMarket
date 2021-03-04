#include <iostream>
#include "ColaPagos.h"
#include "Cliente.h"
using namespace std;

ColaPagos::ColaPagos() {}

void ColaPagos::push(PagosNodo *&frente, PagosNodo *&fin, Cliente *cliente)
{
    PagosNodo *nuevo_nodo = new PagosNodo(cliente);
    nuevo_nodo->setClienteSig(NULL);

    if (isColaVacia(frente))
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin->setClienteSig(nuevo_nodo);
    }

    fin = nuevo_nodo;
}

bool ColaPagos::isColaVacia(PagosNodo *frente)
{
    return (frente == NULL) ? true : false;
}

Cliente *ColaPagos::pop(PagosNodo *&frente, PagosNodo *&fin)
{
    PagosNodo *aux = frente;

    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->getClienteSig();
    }

    Cliente *cliente = aux->getCliente();
    delete aux;
    return cliente;
}

void ColaPagos::mostrarDatos(PagosNodo *frente)
{
    PagosNodo *aux = frente;
    Cliente *cliente = NULL;
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            Cliente *cliente = aux->getCliente();
            aux = aux->getClienteSig();
            cout << "\t\t\t\t@@ Cliente: " << cliente->getCodigo() << " se encuentra en cola para pagar." << endl;
        }
    }
    else
    {
        cout << "\t\t\t\t@@ No hay mas clientes en cola para pagar. " << endl;
    }
}

void ColaPagos::crearCola(int cantidad_clientes, int cantidad_inicial, PagosNodo *&frente, PagosNodo *&fin)
{
    if (cantidad_clientes > 0)
    {
        int id = (rand() % cantidad_clientes) + (1 + cantidad_inicial);
        for (int i = 0; i < cantidad_clientes; i++)
        {
            while (yaExisteCliente(frente, id))
            {
                id = (rand() % cantidad_clientes) + (1 + cantidad_inicial);
            }
            Cliente *nuevo_cliente = new Cliente(id);
            push(frente, fin, nuevo_cliente);
        }
    }
}

bool ColaPagos::yaExisteCliente(PagosNodo *&frente, int id)
{
    PagosNodo *aux = frente;
    while (aux != NULL)
    {
        if (aux->getCliente()->getCodigo() == id)
        {
            return true;
        }
        else
        {
            aux = aux->getClienteSig();
        }
    }

    return false;
}

int ColaPagos::obtenerMayor(PagosNodo *frente)
{
    int actual = 0;
    int siguiente = 0;
    int mayor = 0;
    PagosNodo *aux = frente;
    while (aux != NULL)
    {
        actual = aux->getCliente()->getCodigo();
        aux = aux->getClienteSig();
        if (aux == NULL)
        {
            siguiente = 0;
        }
        else
        {
            siguiente = aux->getCliente()->getCodigo();
        }
        if (actual > siguiente)
        {
            if (actual > mayor)
            {
                mayor = actual;
            }
        }
        else
        {
            if (siguiente > mayor)
            {
                mayor = siguiente;
            }
        }
    }
    return mayor;
}