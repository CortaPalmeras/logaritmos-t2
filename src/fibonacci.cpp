
#include <cmath>

#include "nodo_fibonacci.hpp"

namespace logs {

template <typename llave_t, typename valor_t>
class ColaFibonacci {

    NodoFibonacci<llave_t, valor_t> *minimo;
    int hayArboles = 0;

    void AgregarPar(llave_t llave, valor_t valor) {
        NodoFibonacci<llave_t, valor_t> *arbol = new NodoFibonacci(llave, valor);
        if (hayArboles == 0) {
            minimo = arbol;
            hayArboles++;
        } else if (parMinimo.distancia > distancia) {
            minimo = arbol;
        }
    }

    Par *ExtraerMinimo() {
        NodoFibonacci<llave_t, valor_t> arbolMinimo = minimo;
        Par *resultado = arbolMinimo.raiz;
        auto it = find(arboles.begin(), arboles.end(), arbolMinimo);
        arboles.erase(it);
        int tamaño = arbolMinimo.arboles.size();

        for (int i = 0; i < tamaño; i++) {
            arboles.push_back(arbolMinimo[i]);
            tamaño++;
        }
        int tamañoPunteros = log2_ceil(tamaño);
        NodoFibonacci<llave_t, valor_t> *punteros[tamañoPunteros] = {nullptr};
        for (int k = 0; k < tamaño; k++) {
            funcion(punteros, arbol[k]);
        }
        vector<NodoFibonacci<llave_t, valor_t>> nuevosArboles[tamañoPunteros];
        minimo = punteros[0];
        for (int i = 0; i < tamañoPunteros; i++) {
            nuevosArboles[i] = punteros[i];
            if (minimo.raiz.distancia > punteros[i].raiz.distancia) {
                minimo = punteros[i];
            }
        }
        arboles = nuevosArboles;
        return resultado;
    }
};

template <typename llave_t, typename valor_t>
void funcion(NodoFibonacci<llave_t, valor_t> *punteros, NodoFibonacci<llave_t, valor_t> arbol) {
    if (punteros[arbol.orden] == nullptr) {
        punteros[arbol.orden] = arbol;
    } else {
        NodoFibonacci<llave_t, valor_t> arbol1 = punteros[arbol.orden];
        NodoFibonacci<llave_t, valor_t> arbol2 = arbol;
        if (arbol1.raiz.distancia < arbol2.raiz.distancia) {
            arbol1.arboles.push_back(arbol2);
            punteros[arbol.orden] = nullptr;
            arbol1.orden++;
            funcion(punteros, arbol1);
        } else {
            arbol2.arboles.push_back(arbol1);
            punteros[arbol.orden] = nullptr;
            arbol2.orden++;
            funcion(punteros, arbol2);
        }
    }
}

typedef struct {
    double x;
    double y;
} punto;

template ColaFibonacci<double, *punto>

} // namespace logs
