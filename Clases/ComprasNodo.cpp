#include <iostream>
#include "ComprasNodo.h"
#include "Cliente.h"

ComprasNodo::ComprasNodo(Cliente* cliente){
    this->cliente=cliente;
}

void ComprasNodo::setClienteSig(ComprasNodo* cliente_sig){
    this->cliente_sig=cliente_sig;
}

void ComprasNodo::setCliente(Cliente* cliente){
    this->cliente=cliente;
}

Cliente* ComprasNodo::getCliente(){
    return cliente;
}

ComprasNodo* ComprasNodo::getClienteSig(){
    return cliente_sig;
}