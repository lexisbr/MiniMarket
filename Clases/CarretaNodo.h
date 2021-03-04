#ifndef CARRETANODO_H
#define CARRETANODO_H
#include "Carreta.h"
class CarretaNodo
{
private:
	Carreta *carreta;
	CarretaNodo *carreta_sig;

public:
	CarretaNodo(Carreta *);
	void setCarreta(Carreta *);
	void setCarretaSig(CarretaNodo *);
	Carreta *getCarreta();
	CarretaNodo *getCarretaSig();
};

#endif // ! CARRETANODO_H
