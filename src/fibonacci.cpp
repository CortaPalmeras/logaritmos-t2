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
        ArbolBinomial *punteros[log2_ceil(tamaño)]={nullptr};
        for(int k=0;k<tamaño;k++){
            if(punteros[arboles[k].orden]=nullptr){
                punteros[arboles[k].orden]=arboles[k];
            }
            else{
                if(arboles[k].raiz.distancia>punteros[arboles[k].orden]){
                    arboles[k].arboles.push_back(punteros[arboles[k].orden]);
                }
                else{
                    punteros[arboles[k].orden].arboles.push_back(arboles[k])

                }
            }
        }



        return resultado;
    }

};

void funcion(ArbolBinomial *punteros, ArbolBinomial arboles){
    
}