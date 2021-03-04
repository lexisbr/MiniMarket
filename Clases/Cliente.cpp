#include "Cliente.h"
#include "Carreta.h"
#include <iostream>
using namespace std;

Cliente::Cliente(int codigo) {
	this->codigo = codigo;
}

Cliente::~Cliente(){}

int Cliente::getCodigo() {
	return codigo;
}

void Cliente::setCarreta(Carreta*& carreta) {
	this->carreta = carreta;
}

Carreta* Cliente::getCarreta() {
	return carreta;
}

