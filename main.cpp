#include <iostream>
#include <stdlib.h>
using namespace std;

class Caja{
    private:
        int numeroCaja;
        float tiempoServicio;
        bool estaLibre;
        int cliente;
        int carreta;

    public:
        Caja(int,float,bool,int,int);
        int getNumeroCaja();
        float getTiempoServicio();
        bool isEstaLibre();
        int getCliente();
        int getCarreta();

};

Caja::Caja(int numeroCaja,float tiempoServicio,bool estaLibre,int cliente,int carreta){
    this->numeroCaja = numeroCaja;
    this->tiempoServicio = tiempoServicio;
    this->estaLibre  = estaLibre;
    this->cliente = cliente;
    this->carreta = carreta;
}

int Caja::getNumeroCaja(){
    return numeroCaja;
}

float Caja::getTiempoServicio(){
    return tiempoServicio;
}

bool Caja::isEstaLibre(){
    return estaLibre;
}

int Caja::getCliente(){
    return cliente;
}

int Caja::getCarreta(){
    return carreta;
}


int main(){
    Caja c1 = Caja(1,10,true,1,1);
    cout<<"Tiempo de servicio: "<<c1.getTiempoServicio();
    return 0;
}