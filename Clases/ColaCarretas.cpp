#include <iostream>
#include "ColaCarretas.h"
#include "Cliente.h"
#include "ColaClienteCarretas.h"
using namespace std;

ColaCarretas::ColaCarretas()
{
}

//Crear cola de clientes para las carretas
void ColaCarretas::crearColaCarretas(int cantidad_clientes, ColaClienteCarretas *&frente, ColaClienteCarretas *&fin)
{
    if (cantidad_clientes > 0)
    {
        int id = (rand() % cantidad_clientes) + 1;
        for (int i = 0; i < cantidad_clientes; i++)
        {
            while (yaExisteCliente(frente, id))
            {
                id = (rand() % cantidad_clientes) + 1;
            }
            Cliente *nuevo_cliente = new Cliente(id);
            pushColaCarretas(frente, fin, nuevo_cliente);
        }
    }
}

void ColaCarretas::agregarClientes(int cantidad_clientes, ColaClienteCarretas *&frente, ColaClienteCarretas *&fin)
{
    int cantidad_inicial = cantidadItems(frente);
    int id = (rand() % cantidad_clientes) + (1 + cantidad_inicial);
    for (int i = 0; i < cantidad_clientes; i++)
    {
        while (yaExisteCliente(frente, id))
        {
            cout << "Cantidad de clientes: " << cantidad_clientes << " Cantidad inicial" << cantidad_inicial << endl;
            id = (rand() % cantidad_clientes) + (1 + cantidad_inicial);
        }
        Cliente *nuevo_cliente = new Cliente(id);
        pushColaCarretas(frente, fin, nuevo_cliente);
        cantidad_inicial = cantidadItems(frente);
    }
}

int ColaCarretas::cantidadItems(ColaClienteCarretas *&frente)
{
    int cont = 0;
    ColaClienteCarretas *aux = frente;
    while (aux != NULL)
    {
        cout << "Cliente " << aux->getCliente()->getCodigo() << endl;
        aux = aux->getClienteSig();
        cont++;
    }

    return cont;
}

bool ColaCarretas::yaExisteCliente(ColaClienteCarretas *&frente, int id)
{
    ColaClienteCarretas *aux = frente;
    while (aux != NULL)
    {
        if (aux->getCliente()->getCodigo() == id)
            return true;
        else
            aux = aux->getClienteSig();
    }

    return false;
}

//Funcion para insertar un nuevo cliente a la cola de carretas
void ColaCarretas::pushColaCarretas(ColaClienteCarretas *&frente, ColaClienteCarretas *&fin, Cliente *cliente)
{
    ColaClienteCarretas *nuevo_nodo = new ColaClienteCarretas(cliente);
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

    cout << ">> Cliente " << nuevo_nodo->getCliente()->getCodigo() << " ingresa a cola para adquirir carreta." << endl;
}

//Funcion para saber si la cola de clientes para carretas esta vacia
bool ColaCarretas::isColaVacia(ColaClienteCarretas *frente)
{
    return (frente == NULL) ? true : false;
}

// Desencolar el primer elemento insertado
Cliente *ColaCarretas::popColaCarretas(ColaClienteCarretas *&frente, ColaClienteCarretas *&fin)
{
    ColaClienteCarretas *aux = frente;

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
    //   cout << "Cliente: " << cliente->getCodigo()<<" sale de cola para tomar una carreta."<< endl;

    delete aux;

    return cliente;
}

void ColaCarretas::mostrarColaCarretas(ColaClienteCarretas *frente)
{
    ColaClienteCarretas *aux = frente;
    Cliente *cliente = NULL;
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            cliente = aux->getCliente();
            aux = aux->getClienteSig();
            cout << "-- Cliente: " << cliente->getCodigo() << " se encuentra en cola para carretas." << endl;
        }
    }
    else
    {
        cout << "\t\t-- No hay clientes en la cola para carretas." << endl;
    }
}