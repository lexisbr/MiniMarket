#include <iostream>
#include "CajaNodo.h"
#include "Caja.h"

CajaNodo::CajaNodo(Caja* caja){
    this->caja = caja;
}

void CajaNodo::setCaja(Caja* caja){
    this->caja=caja;
}

void CajaNodo::setCajaSig(CajaNodo* caja_sig){
    this->caja_sig=caja_sig;
}

void CajaNodo::setCajaAnt(CajaNodo* caja_ant){
    this->caja_ant=caja_ant;
}

Caja* CajaNodo::getCaja(){
    return caja;
}

CajaNodo* CajaNodo::getCajaSig(){
    return caja_sig;
}

CajaNodo* CajaNodo::getCajaAnt(){
    return caja_ant;
}