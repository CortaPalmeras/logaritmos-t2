
#include <cmath>

#include "fibonacci.hpp"
#include "nodo_fibonacci.hpp"

namespace logs {

int log2_ceil(int x) {
    return static_cast<int>(ceil(log2(x)));
}

void funcion(ArbolBinomial **punteros, ArbolBinomial arbol){
    if(punteros[arbol.orden]==nullptr){
        punteros[arbol.orden]=&arbol;
    }
    else{
        ArbolBinomial arbol1=*punteros[arbol.orden];
        ArbolBinomial arbol2=arbol;
        punteros[arbol.orden]=nullptr;
        if(arbol1.raiz.distancia<arbol2.raiz.distancia){
            arbol1.arboles.push_back(arbol2);
            arbol1.orden++;
            funcion(punteros,arbol1);
        }
        else{
            arbol2.arboles.push_back(arbol1);
            arbol2.orden++;
            funcion(punteros,arbol2);
        }
    }
}

void ColaFibonacci::AgregarPar(int distancia, Nodo *nodo){
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
    else if(minimo.raiz.distancia>distancia){
        minimo=arbol;
    }
}

Par ColaFibonacci::*ExtraerMinimo(){
    ArbolBinomial arbolMinimo=minimo;
    Par *resultado=&arbolMinimo.raiz;
    auto it = find(arboles.begin(), arboles.end(), arbolMinimo);
    arboles.erase(it);
    int tamaño=arbolMinimo.arboles.size();

    for(int i=0;i<tamaño;i++){
        arboles.push_back(arbolMinimo.arboles[i]);
        // tamaño++;
    }

    int tamañoPunteros=log2_ceil(arboles.size());
    ArbolBinomial *punteros[tamañoPunteros]={nullptr};
    for(int k=0;k<arboles.size();k++){
        funcion(punteros,arboles[k]);
    }
    arboles.clear();
    ArbolBinomial nuevo_minimo;
    nuevo_minimo.raiz.distancia=numeric_limits<int>::max();
    for(int i=0;i<tamañoPunteros;i++){
        arboles.push_back(*punteros[i]);
        if(arboles[i].raiz.distancia<nuevo_minimo.raiz.distancia){
            nuevo_minimo=arboles[i];
        }
    }
    minimo=nuevo_minimo;
    return resultado;
}

void ColaFibonacci::DecreaseKey(Nodo nodo, int nuevaDistancia){
    nodo.par->distancia=nuevaDistancia;
}

}
