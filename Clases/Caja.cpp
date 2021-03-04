#include "Caja.h"
#include <iostream>
using namespace std;

Caja::Caja(int numeroCaja, int tiempoServicio, bool estaLibre)
{
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->estaLibre = estaLibre;
    this->contador_pasos = 0;
}

int Caja::getNumeroCaja()
{
    return numeroCaja;
}

int Caja::getTiempoServicio()
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

int Caja::getContadorPasos()
{
    return contador_pasos;
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

void Caja::incrementContadorPasos(){
    contador_pasos++;
}