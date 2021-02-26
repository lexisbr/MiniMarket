#include "Caja.h"
#include <iostream>
using namespace std;


Caja::Caja(int numeroCaja, float tiempoServicio, bool estaLibre, int cliente) {
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->estaLibre = estaLibre;
    this->cliente = cliente;
}

int Caja::getNumeroCaja() {
    return numeroCaja;
}

float Caja::getTiempoServicio() {
    return tiempoServicio;
}

bool Caja::isEstaLibre() {
    return estaLibre;
}

int Caja::getCliente() {
    return cliente;
}

void Caja::setTiempoServicio(float tiempoServicio) {
    this->tiempoServicio = tiempoServicio;
}

void Caja::setEstaLibre(bool estaLibre) {
    this->estaLibre = estaLibre;
}
