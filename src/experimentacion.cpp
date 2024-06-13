
#include "heap.hpp"
#include <random>
#include <vector>

using namespace std;

int aleatorioEntero(int inicio, int fin) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(inicio, fin);
    int resultado = dis(gen);
    return resultado;
}
double aleatorioDecimal(double inicio, double fin) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(inicio, fin);
    double resultado = dis(gen);
    return resultado;
}

pair<vector<logs::Nodo>, vector<vector<logs::Arista>>> *crear_grafo(int i, int j) {

    pair<vector<Nodo>, vector<vector<Arista>>> *par = new pair<vector<Nodo>, vector<vector<Arista>>>;
    vector<Nodo> nodos;
    vector<vector<Arista>> aristas;

    for (int k = 0; k < i; k++) {
        Nodo nodo;
        nodos.push_back(nodo);
    }

    par->first = nodos;
    int v = pow(2, i);
    int e = pow(2, j);

    for (int k = v - 1; k > 0; k--) {

        Arista arista;
        int aleatorio = aleatorioEntero(1, k - 1);
        double peso = aleatorioDecimal(0.0, 1.0);
        arista.nodo1 = nodos[k];
        arista.nodo2 = nodos[aleatorio];
        arista.peso = peso;
        aristas[k].push_back(arista);
    }

    for (int i = 0; i < e - (v - 1); i++) {

        int nodoAleatorioInicio = aleatorioEntero(0, v);
        int nodoAleatorioFinal = aleatorioEntero(0, v);
        Arista aristaCandidata;

        aristaCandidata.nodo1 = nodos[nodoAleatorioInicio];
        aristaCandidata.nodo2 = nodos[nodoAleatorioFinal];

        while (nodoAleatorioInicio == nodoAleatorioFinal ||
               find(aristas.begin(), aristas.end(), aristaCandidata) == aristas.end()) {
            int nodoAleatorioInicio = aleatorioEntero(0, v);
            int nodoAleatorioFinal = aleatorioEntero(0, v);
            aristaCandidata.nodo1 = nodos[nodoAleatorioInicio];
            aristaCandidata.nodo2 = nodos[nodoAleatorioFinal];
        }

        aristas[i].push_back(aristaCandidata);
    }

    (*par).second = aristas;
    return par;
}
