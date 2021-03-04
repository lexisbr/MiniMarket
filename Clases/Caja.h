#ifndef CAJA_H
#define CAJA_H
#include "Cliente.h"
class Caja {
private:
    int numeroCaja;
    int tiempoServicio;
    bool estaLibre;
    Cliente* cliente;
    int contador_pasos;
public:
    Caja(int, int, bool);
    int getNumeroCaja();
    int getTiempoServicio();
    bool isEstaLibre();
    Cliente* getCliente();
    int getContadorPasos();
    void setNumeroCaja(int);
    void setTiempoServicio(float);
    void setEstaLibre(bool);
    void setCliente(Cliente*&);
    void incrementContadorPasos();
};
#endif