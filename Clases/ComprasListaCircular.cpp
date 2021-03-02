#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include "ComprasListaCircular.h"
#include "ComprasNodo.h"
#include "Cliente.h"
using namespace std;

ComprasListaCircular::ComprasListaCircular()
{
}

void ComprasListaCircular::addCliente(ComprasNodo *&frente, ComprasNodo *&fin, Cliente *cliente)
{
    ComprasNodo *nuevo_nodo = new ComprasNodo(cliente);
    nuevo_nodo->setClienteSig(NULL);

    if (isColaVacia(frente))
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin->setClienteSig(nuevo_nodo);
    }

    nuevo_nodo->setClienteSig(frente);
    fin = nuevo_nodo;
}

//Funcion para saber si la cola de clientes para carretas esta vacia
bool ComprasListaCircular::isColaVacia(ComprasNodo *frente)
{
    return (frente == NULL) ? true : false;
}

// Desencolar el primer elemento insertado
Cliente *ComprasListaCircular::popCliente(ComprasNodo *&frente, ComprasNodo *&fin)
{
    int indice = rand() % 101;
    int indice_aux = 0;
    ComprasNodo *aux = frente;
    ComprasNodo *nodo_anterior = aux;

    while (aux != NULL)
    {
        if (indice == indice_aux)
        {
            while (nodo_anterior != NULL)
            {
                if (nodo_anterior->getClienteSig()->getCliente() == aux->getCliente())
                {
                    //Cliente *cliente_anterior = nodo_anterior->getCliente();
                    if (frente == aux)
                    {
                        frente = frente->getClienteSig();
                        fin->setClienteSig(frente);
                    }
                    else if (fin == aux)
                    {
                        fin = nodo_anterior;
                        fin->setClienteSig(frente);
                    }
                    else
                    {
                        nodo_anterior->setClienteSig(aux->getClienteSig());
                    }
                    Cliente *cliente = aux->getCliente();
                    cout << "Cliente: " << cliente->getCodigo() << " sale de lista de compras." << endl;
                    delete aux;
                    return cliente;
                }
                else
                {
                    nodo_anterior = nodo_anterior->getClienteSig();
                }
            }
        }
        else
        {
            aux = aux->getClienteSig();
        }
    }

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
    cout << "Cliente: " << cliente->getCodigo() << " sale de cola para tomar una carreta." << endl;
}

void ComprasListaCircular::mostrarDatos(ComprasNodo *&frente, ComprasNodo *&fin)
{
    ComprasNodo *aux = frente;
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            Cliente *cliente = aux->getCliente();
            aux = aux->getClienteSig();
            if (cliente == fin->getCliente())
            {
                aux = NULL;
            }
            cout << "\t\t\t## Cliente: " << cliente->getCodigo() << " se encuentra comprando. " << endl;
        }
    }
    else
    {
        cout << "\t\t\t## No hay clientes comprando. " << endl;
    }
}

void ComprasListaCircular::crearListaCompras(ComprasNodo *&frente, ComprasNodo *&fin, int cantidad_clientes, int cantidad_clientes_carretas)
{
    if (cantidad_clientes > 0)
    {
        int id = (rand() % cantidad_clientes) + (1 + cantidad_clientes_carretas);
        for (int i = 0; i < cantidad_clientes; i++)
        {
            while (yaExisteCliente(frente, fin, id))
            {
                id = (rand() % cantidad_clientes) + (1 + cantidad_clientes_carretas);
            }
            Cliente *nuevo_cliente = new Cliente(id);
            addCliente(frente, fin, nuevo_cliente);
            //cout << "\t\t\t## Cliente " << fin->getCliente()->getCodigo() << " Se encuentra comprando." << endl;
        }
    }
}

bool ComprasListaCircular::yaExisteCliente(ComprasNodo *&frente, ComprasNodo *&fin, int id)
{
    ComprasNodo *aux = frente;
    bool final = false;
    while (!final && fin != NULL)
    {
        if (aux == fin)
        {
            final = true;
        }
        if (aux->getCliente()->getCodigo() == id)
            return true;
        else
        {
            aux = aux->getClienteSig();
        }
    }
    return false;
}
