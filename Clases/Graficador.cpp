#include "Graficador.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void Graficador::writeFile(string grafo)
{
    ofstream myfile;
    myfile.open("grafica.dot");
    myfile << "digraph G {\n";
    myfile << "label = \"MiniMarket\"\n";
    //    myfile << "rankdir = \"LR\"\n";
    myfile << "graph [fontsize=10 fontname=\"Verdana\"]\n";
    myfile << "node [shape=record fontsize=10 fontname=\"Verdana\"]\n";
    myfile << grafo;
    myfile << "}\n";
    myfile.close();
    system("dot -Tpng grafica.dot -o grafica.png");
}

string Graficador::graficarColaCarretas(ColaClienteCarretas *frente_colaCarretas)
{
    ColaClienteCarretas *aux = frente_colaCarretas;
    string grafo;
    Cliente *cliente = NULL;
    if (aux != NULL)
    {
        grafo.append("subgraph cluster_0 {\n");
        grafo.append("node [style=filled];\n");
        while (aux != NULL)
        {
            cliente = aux->getCliente();
            aux = aux->getClienteSig();
            string cliente_str = to_string(cliente->getCodigo());
            grafo.append("\"->Cliente: " + cliente_str + "\"");
            if (aux != NULL)
            {
                string cliente_sig_str = to_string(aux->getCliente()->getCodigo());
                grafo.append("->\"->Cliente: " + cliente_sig_str);
                grafo.append("\";\n");
            }
            else
            {
                grafo.append(";\n");
            }
        }
        grafo.append("label=\"Cola para Carretas\";\n color=blue;\n }\n");
        return grafo;
    }
}

string Graficador::graficarPilaCarretas1(CarretaNodo *frente_pilaCarreta1)
{
    CarretaNodo *aux_pila = frente_pilaCarreta1;
    string grafo;
    if (aux_pila != NULL)
    {
        grafo.append("subgraph cluster_1 {\n");
        grafo.append("node [style=filled];\n");
        while (aux_pila != NULL)
        {
            Carreta *carreta = aux_pila->getCarreta();
            aux_pila = aux_pila->getCarretaSig();
            string carreta_str = to_string(carreta->getCodigo());
            grafo.append("\"->Carreta: " + carreta_str + "\"");
            if (aux_pila != NULL)
            {
                string carreta_sig_str = to_string(aux_pila->getCarreta()->getCodigo());
                grafo.append("->\"->Carreta: " + carreta_sig_str);
                grafo.append("\";\n");
            }
            else
            {
                grafo.append(";\n");
            }
        }
        grafo.append("label=\"Pila 1 de Carretas\";\n color=brown4;\n }\n");
        return grafo;
    }
}

string Graficador::graficarPilaCarretas2(CarretaNodo *frente_pilaCarreta1)
{
    CarretaNodo *aux_pila = frente_pilaCarreta1;
    string grafo;
    if (aux_pila != NULL)
    {
        grafo.append("subgraph cluster_2 {\n");
        grafo.append("node [style=filled];\n");
        while (aux_pila != NULL)
        {
            Carreta *carreta = aux_pila->getCarreta();
            aux_pila = aux_pila->getCarretaSig();
            string carreta_str = to_string(carreta->getCodigo());
            grafo.append("\"->Carreta: " + carreta_str + "\"");
            if (aux_pila != NULL)
            {
                string carreta_sig_str = to_string(aux_pila->getCarreta()->getCodigo());
                grafo.append("->\"->Carreta: " + carreta_sig_str);
                grafo.append("\";\n");
            }
            else
            {
                grafo.append(";\n");
            }
        }
        grafo.append("label=\"Pila 2 de Carretas\";\n color=forestgreen;\n }\n");
        return grafo;
    }
}

string Graficador::graficarListaCompras(ComprasNodo *frente, ComprasNodo *fin)
{
    ComprasNodo *aux = frente;
    string grafo;
    if (aux != NULL)
    {
        grafo.append("subgraph cluster_3 {\n");
        grafo.append("node [style=filled];\n");
        while (aux != NULL)
        {
            Cliente *cliente = aux->getCliente();
            aux = aux->getClienteSig();
            string cliente_str = to_string(cliente->getCodigo());
            string carreta_str = to_string(cliente->getCarreta()->getCodigo());
            grafo.append("\"->Cliente: " + cliente_str + " ->Carreta: " + carreta_str + "\"");
            if (aux != NULL)
            {
                string cliente_sig_str = to_string(aux->getCliente()->getCodigo());
                string carreta_sig_str = to_string(aux->getCliente()->getCarreta()->getCodigo());
                grafo.append("->\"->Cliente: " + cliente_sig_str + " ->Carreta: " + carreta_sig_str);
                grafo.append("\";\n");
            }
            else
            {
                grafo.append(";\n");
            }
            if (cliente == fin->getCliente())
            {
                aux = NULL;
            }
        }
        grafo.append("label=\"Lista Circular de Compras\";\n color=crimson;\n }\n");
        return grafo;
    }
}

string Graficador::graficarColaPagos(PagosNodo *frente)
{
    PagosNodo *aux = frente;
    string grafo;
    Cliente *cliente = NULL;
    if (aux != NULL)
    {
        grafo.append("subgraph cluster_4 {\n");
        grafo.append("node [style=filled];\n");
        while (aux != NULL)
        {
            Cliente *cliente = aux->getCliente();
            aux = aux->getClienteSig();
            string cliente_str = to_string(cliente->getCodigo());
            grafo.append("\"->Cliente: " + cliente_str + "\"");
            if (aux != NULL)
            {
                string cliente_sig_str = to_string(aux->getCliente()->getCodigo());
                grafo.append("->\"->Cliente: " + cliente_sig_str);
                grafo.append("\";\n");
            }
            else
            {
                grafo.append(";\n");
            }
        }
        grafo.append("label=\"Cola para Pagos\";\n color=fuchsia;\n }\n");
        return grafo;
    }
}

string Graficador::graficarListaCajas(CajaNodo *frente)
{
    CajaNodo *aux = frente;
    string grafo;
    grafo.append("subgraph cluster_5 {\n");
    grafo.append("node [style=filled];\n");
    while (aux != NULL)
    {
        CajaNodo *caja = aux;
        aux = aux->getCajaSig();
        string caja_str = to_string(caja->getCaja()->getNumeroCaja());
        string tiempo = to_string(caja->getCaja()->getTiempoServicio());
        grafo.append("\"->Caja: " + caja_str);
        grafo.append(" ->Turnos: " + tiempo);
        if (caja->getCaja()->isEstaLibre())
        {
            grafo.append(" ->Estado: Libre\"");
        }
        else
        {
            grafo.append(" ->Estado: Ocupado");
            string cliente = to_string(caja->getCaja()->getCliente()->getCodigo());
            grafo.append(" ->Cliente: " + cliente);
            grafo.append("\"");
        }

        if (aux != NULL)
        {
            string caja_sig_str = to_string(aux->getCaja()->getNumeroCaja());
            string tiempo = to_string(aux->getCaja()->getTiempoServicio());
            grafo.append("->\"->Caja: " + caja_sig_str);
            grafo.append(" ->Turnos: " + tiempo);
            if (aux->getCaja()->isEstaLibre())
            {
                grafo.append(" ->Estado: Libre");
            }
            else
            {
                grafo.append(" ->Estado: Ocupado");
                string cliente = to_string(aux->getCaja()->getCliente()->getCodigo());
                grafo.append(" ->Cliente: " + cliente);
            }
            grafo.append("\";\n");
        }
        else
        {
            grafo.append(";\n");
        }

        if (caja->getCajaAnt() != NULL)
        {
            grafo.append("\"->Caja: " + caja_str);
            grafo.append(" ->Turnos: " + tiempo);
            if (caja->getCaja()->isEstaLibre())
            {
                grafo.append(" ->Estado: Libre\"");
            }
            else
            {
                grafo.append(" ->Estado: Ocupado");
                string cliente = to_string(caja->getCaja()->getCliente()->getCodigo());
                grafo.append(" ->Cliente: " + cliente);
                grafo.append("\"");
            }
            string caja_ant_str = to_string(caja->getCajaAnt()->getCaja()->getNumeroCaja());
            string tiempo = to_string(caja->getCajaAnt()->getCaja()->getTiempoServicio());
            grafo.append("->\"->Caja: " + caja_ant_str);
            grafo.append(" ->Turnos: " + tiempo);
            if (caja->getCajaAnt()->getCaja()->isEstaLibre())
            {
                grafo.append(" ->Estado: Libre");
            }
            else
            {
                grafo.append(" ->Estado: Ocupado");
                string cliente = to_string(caja->getCajaAnt()->getCaja()->getCliente()->getCodigo());
                grafo.append(" ->Cliente: " + cliente);
            }
            grafo.append("\";\n");
        }
    }
    grafo.append("label=\"Lista de Cajas\";\n color=fuchsia;\n }\n");
    return grafo;
}
