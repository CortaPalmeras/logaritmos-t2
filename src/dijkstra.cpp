
#include <limits>
#include <random>
#include <vector>

#include "cola_fibonacci.hpp"
#include "dijkstra.hpp"

using std::vector;

void dijkstra_fibonacci(int raiz, const Grafo& grafo, vector<int>& previo,
                        vector<double>& distancias) {
    int n = grafo.size();

    // paso 2
    ColaFibonacci<double, int> cola;

    // paso 3 y 4
    previo.assign(n, -1);
    distancias.assign(n, std::numeric_limits<double>::max());
    distancias[raiz] = 0;

    // paso 5
    vector<ColaFibonacci<double, int>::Nodo*> nodos;
    vector<bool> extraido(n, false);
    nodos.reserve(n);

    // heapify
    for (int i = 0; i < n; i++) {
        nodos.push_back(cola.agregarPar(distancias[i], i));
    }

    // paso 6
    while (!cola.vacio()) {
        int v = cola.extraerMinimo();
        extraido[v] = true;

        for (auto& vecino : grafo[v]) {
            int u = vecino.first;
            double dist_vu = vecino.second;

            if (!extraido[u] && distancias[v] + dist_vu < distancias[u]) {
                distancias[u] = distancias[v] + dist_vu;
                previo[u] = v;
                cola.reducirLlave(nodos[u], distancias[v] + dist_vu);
            }
        }
    }
}

std::default_random_engine rng(59);

int aleatorioEntero(int inicio, int fin) {
    std::uniform_int_distribution<int> dist(inicio, fin);
    return dist(rng);
}

double aleatorioDecimal(double inicio, double fin) {
    std::uniform_real_distribution<double> dist(inicio, fin);
    return dist(rng);
}

void unir_nodos(Grafo& grafo, int nodo1, int nodo2, double peso) {
    grafo[nodo1].emplace_back(nodo2, peso);
    grafo[nodo2].emplace_back(nodo1, peso);
}

Grafo crear_grafo(int i, int j) {
    int v = pow(2, i);
    int e = pow(2, j);

    Grafo grafo(v);

    for (int nodo_actual = 1; nodo_actual < v; nodo_actual++) {
        int otro_nodo = aleatorioEntero(0, nodo_actual - 1);
        double peso = aleatorioDecimal(0, 1);

        unir_nodos(grafo, nodo_actual, otro_nodo, peso);
    }

    for (int n = 0; n < e - (v - 1); n++) {
        int nodo1 = aleatorioEntero(0, v);
        int nodo2 = aleatorioEntero(0, v);
        double peso = aleatorioDecimal(0, 1);

        while (nodo1 == nodo2) {
            nodo2 = aleatorioEntero(0, v);
        }

        unir_nodos(grafo, nodo1, nodo2, peso);
    }

    return grafo;
}

