#include<iostream>
#include "CarretaNodo.h"
#include "Carreta.h"

CarretaNodo::CarretaNodo(Carreta* carreta) {
	this->carreta = carreta;
}

void CarretaNodo::setCarreta(Carreta* carreta) {
	this->carreta = carreta;
}

void CarretaNodo::setCarretaSig(CarretaNodo* carreta_sig) {
	this->carreta_sig = carreta_sig;
}

Carreta* CarretaNodo::getCarreta() {
	return carreta;
}

CarretaNodo* CarretaNodo::getCarretaSig() {
	return carreta_sig;
}


