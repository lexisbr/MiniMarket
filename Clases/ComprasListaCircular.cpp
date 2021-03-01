#include <iostream>
#include "ComprasListaCircular.h"
#include "ComprasNodo.h"
#include "Cliente.h"
using namespace std;

ComprasListaCircular::ComprasListaCircular(){

}

void ComprasListaCircular::addCliente(ComprasNodo*& frente,ComprasNodo*& fin, Cliente* cliente ){
    ComprasNodo* nuevo_nodo = new ComprasNodo(cliente);
    nuevo_nodo->setClienteSig(NULL);

    if(isColaVacia(frente)){
        frente = nuevo_nodo;
    }
    else{
        fin->setClienteSig(nuevo_nodo);
    }
    
    nuevo_nodo->setClienteSig(frente);
    fin = nuevo_nodo;

    cout<<"Cliente "<<fin->getCliente()->getCodigo()<<" ingresa a comprar. Siguiente: "<<fin->getClienteSig()->getCliente()->getCodigo()<<endl;

}

//Funcion para saber si la cola de clientes para carretas esta vacia
bool ComprasListaCircular::isColaVacia(ComprasNodo* frente) {
    return (frente == NULL) ? true : false;
}