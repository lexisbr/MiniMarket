#ifndef CAJA_H
#define CAJA_H
#include "Cliente.h"
class Caja {
private:
    int numeroCaja;
    float tiempoServicio;
    bool estaLibre;
    Cliente* cliente;
public:
    Caja(int, float, bool);
    int getNumeroCaja();
    float getTiempoServicio();
    bool isEstaLibre();
    Cliente* getCliente();
    void setNumeroCaja(int);
    void setTiempoServicio(float);
    void setEstaLibre(bool);
    void setCliente(Cliente*&);
};
#endif