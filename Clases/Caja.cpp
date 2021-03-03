#include "Caja.h"
#include <iostream>
using namespace std;

Caja::Caja(int numeroCaja, float tiempoServicio, bool estaLibre)
{
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->estaLibre = estaLibre;
}

int Caja::getNumeroCaja()
{
    return numeroCaja;
}

float Caja::getTiempoServicio()
{
    return tiempoServicio;
}

bool Caja::isEstaLibre()
{
    return estaLibre;
}

Cliente *Caja::getCliente()
{
    return cliente;
}

void Caja::setNumeroCaja(int numeroCaja)
{
    this->numeroCaja = numeroCaja;
}

void Caja::setTiempoServicio(float tiempoServicio)
{
    this->tiempoServicio = tiempoServicio;
}

void Caja::setEstaLibre(bool estaLibre)
{
    this->estaLibre = estaLibre;
}

void Caja::setCliente(Cliente *&cliente)
{
    this->cliente = cliente;
}