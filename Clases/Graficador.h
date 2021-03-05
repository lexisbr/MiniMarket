#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <string>
#include "ColaClienteCarretas.h"
#include "CarretaNodo.h"
#include "ComprasNodo.h"
#include "PagosNodo.h"
#include "CajaNodo.h"
class Graficador
{
public:
    void writeFile(std::string);
    std::string graficarColaCarretas(ColaClienteCarretas *);
    std::string graficarPilaCarretas1(CarretaNodo *);
    std::string graficarPilaCarretas2(CarretaNodo *);
    std::string graficarListaCompras(ComprasNodo*,ComprasNodo*);
    std::string graficarColaPagos(PagosNodo*);
    std::string graficarListaCajas(CajaNodo*);
};
#endif