#ifndef CAJANODO_H
#define CAJANODO_H
#include "Caja.h"
class CajaNodo
{
private:
    Caja *caja;
    CajaNodo *caja_sig;
    CajaNodo *caja_ant;

public:
    CajaNodo(Caja *);
    void setCaja(Caja *);
    void setCajaSig(CajaNodo *);
    void setCajaAnt(CajaNodo *);
    Caja *getCaja();
    CajaNodo *getCajaSig();
    CajaNodo *getCajaAnt();
};
#endif /* CAJANODO_H */