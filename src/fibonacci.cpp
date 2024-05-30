#include "tarea.hpp"
#include "arbol_binomial.cpp"
#include <limits>
#include <cmath>



int log2_ceil(int x) {
    return static_cast<int>(ceil(log2(x)));
}

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
            minimo=arbol;
        }
    }
    Par *ExtraerMinimo(){
        ArbolBinomial arbolMinimo=minimo;
        Par *resultado=arbolMinimo.raiz;
        auto it = find(arboles.begin(), arboles.end(), arbolMinimo);
        arboles.erase(it);
        int tamaño=arbolMinimo.arboles.size();

        for(int i=0;i<tamaño;i++){
            arboles.push_back(arbolMinimo[i]);
            tamaño++;
        }
        int tamañoPunteros=log2_ceil(tamaño);
        ArbolBinomial *punteros[tamañoPunteros]={nullptr};
        for(int k=0;k<tamaño;k++){
            funcion(punteros,arbol[k]);
        }
        vector<ArbolBinomial> nuevosArboles[tamañoPunteros];
        minimo=punteros[0];
        for(int i=0;i<tamañoPunteros;i++){
            nuevosArboles[i]=punteros[i];
            if(minimo.raiz.distancia>punteros[i].raiz.distancia){
                minimo=punteros[i];
            }
        }
        arboles=nuevosArboles;
        return resultado;
    }

};

void funcion(ArbolBinomial *punteros, ArbolBinomial arbol){
    if(punteros[arbol.orden]==nullptr){
        punteros[arbol.orden]=arbol;
    }
    else{
        ArbolBinomial arbol1=punteros[arbol.orden];
        ArbolBinomial arbol2=arbol;
        if(arbol1.raiz.distancia<arbol2.raiz.distancia){
            arbol1.arboles.push_back(arbol2);
            punteros[arbol.orden]=nullptr;
            arbol1.orden++;
            funcion(punteros,arbol1);
        }
        else{
            arbol2.arboles.push_back(arbol1);
            punteros[arbol.orden]=nullptr;
            arbol2.orden++;
            funcion(punteros,arbol2);
        }
    }
}