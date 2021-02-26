#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(int codigo) {
	this->codigo = codigo;
}

int Cliente::getCodigo() {
	return codigo;
}

