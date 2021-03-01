#include "Carreta.h"
#include <iostream>
using namespace std;

Carreta::Carreta(int codigo) {
	this->codigo = codigo;
}

int Carreta::getCodigo() {
	return codigo;
}