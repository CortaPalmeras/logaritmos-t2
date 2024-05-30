#include "tarea.hpp"
#include "arbol_binomial.cpp"
#include <limits>

class ColaFibonacci{
    vector <ArbolBinomial>arboles;
    ArbolBinomial minimo;
    int hayArboles=0;
    void AgregarPar(int distancia, Nodo *nodo){
        Par par;
        par.distancia=distancia;
        par.nodo=nodo;
        ArbolBinomial arbol;
        arbol.orden=0;
        arbol.raiz=par;
        if(hayArboles==0){
            minimo=arbol;
            hayArboles++;
        }
        else if(parMinimo.distancia>distancia){
            minimo=
        }
    }
    Par *ExtraerMinimo(){

    }

};