#include <iostream>
#include "ListaCajas.h"
#include "CajaNodo.h"
using namespace std;

ListaCajas::ListaCajas() {}

void ListaCajas::add(CajaNodo *&frente, CajaNodo *&fin, Caja *caja)
{
    CajaNodo *nuevo_nodo = new CajaNodo(caja);
    nuevo_nodo->setCajaSig(NULL);
    nuevo_nodo->setCajaAnt(NULL);

    if (frente == NULL)
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin->setCajaSig(nuevo_nodo);
        nuevo_nodo->setCajaAnt(fin);
    }
    fin = nuevo_nodo;
}

void ListaCajas::show(CajaNodo *frente)
{
    CajaNodo *aux = frente;
    while (aux != NULL)
    {
        CajaNodo *caja = aux;
        aux = aux->getCajaSig();

        cout<<"Caja "<<caja->getCaja()->getNumeroCaja();
        if(caja->getCajaSig()!=NULL)
        {
            cout<<" Siguiente -> "<<caja->getCajaSig()->getCaja()->getNumeroCaja()<<endl;
        }
        if(caja->getCajaAnt()!=NULL)
        {
            cout<<" Anterior -> "<<caja->getCajaAnt()->getCaja()->getNumeroCaja()<<endl;

        }
    //    cout << " Caja: " << caja->getCaja()->getNumeroCaja() << " Siguiente->" << caja->getCajaSig()->getCaja()->getNumeroCaja() << endl;
       // cout << " Caja: " << caja->getCaja()->getNumeroCaja() << " Siguiente->" << caja->getCajaSig()->getCaja()->getNumeroCaja() << " Anterior->" << caja->getCajaAnt()->getCaja()->getNumeroCaja() << endl;
    }
}

void ListaCajas::crearCajas(CajaNodo *&frente, CajaNodo *&fin, int cantidad_cajas){
    if(cantidad_cajas>0)
    {
        
    }

}