#include<iostream>
#include "PagosNodo.h"
#include "Cliente.h"

 PagosNodo::PagosNodo(Cliente *cliente){
     this->cliente = cliente;
 }

void PagosNodo::setCliente(Cliente *cliente){
    this->cliente = cliente;
}

void PagosNodo::setClienteSig(PagosNodo *cliente_sig){
    this->cliente_sig = cliente_sig;
}

Cliente* PagosNodo::getCliente(){
    return cliente;
}

PagosNodo* PagosNodo::getClienteSig(){
    return cliente_sig;
}