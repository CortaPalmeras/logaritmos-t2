#include <cstdio>
#include <vector>

#include "heap.hpp"
#include "tarea.hpp"

using namespace std;

vector<Par> pares;
int tamaño = 0;

void Heap::AgregarPar(int distancia, Nodo *nodo) {
    Par par = {distancia, nodo};
    pares.push_back(par);
    Subir();
    tamaño++;
}

void Heap::Subir() {
    int j = tamaño;
    while (j >= 1 && pares[j].distancia < pares[(j - 1) / 2].distancia) {
        Par par1 = pares[j];
        Par par2 = pares[(j - 1) / 2];
        pares[j] = par2;
        pares[(j - 1) / 2] = par1;
        j = (j - 1) / 2;
    }
}

void Heap::Bajar() {
    int j = tamaño;
    while (2 * j + 1 < tamaño) {
        int k = 2 * j + 1;
        if (k + 1 < tamaño && pares[k + 1].distancia < pares[k].distancia) {
            k++;
        }
        if (pares[j].distancia <= pares[k].distancia) {
            break;
        }
        Par par1 = pares[j];
        Par par2 = pares[k];
        pares[j] = par1;
        pares[k] = par2;
        j = k;
    }
}

Par *Heap::ExtraerMinimo() {
    Par *minimo = &pares[0];
    tamaño--;
    pares[0] = pares[tamaño];
    Bajar();
    return minimo;
}

void Heap::DecreaseKey(Nodo nodo, int nuevaDistancia) {
    nodo.par->distancia = nuevaDistancia;
}
