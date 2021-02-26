#ifndef CAJA_H
#define CAJA_H
class Caja {
private:
    int numeroCaja;
    float tiempoServicio;
    bool estaLibre;
    int cliente;
public:
    Caja(int, float, bool, int);
    int getNumeroCaja();
    float getTiempoServicio();
    bool isEstaLibre();
    int getCliente();
    void setTiempoServicio(float);
    void setEstaLibre(bool);
};
#endif