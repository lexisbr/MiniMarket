#ifndef CLIENTE_H
#define CLIENTE_H
#include "Carreta.h"
class Cliente {
private:
	int codigo;
	Carreta* carreta;
public:
	Cliente(int);
	~Cliente();
	int getCodigo();
	void setCarreta(Carreta*&);
	Carreta* getCarreta();
};
#endif