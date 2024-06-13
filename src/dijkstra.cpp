
#include <limits>
#include <vector>

#include "cola_fibonacci.hpp"

namespace logs {

using std::vector, std::pair;

void dijkstra(int raiz, vector<vector<pair<int, double>>> const &grafo) {
    int n = grafo.size();

    // paso 1 y 4
    vector<int> previo(n, -1);
    vector<double> distancias(n, std::numeric_limits<double>::max());

    // paso 2
    ColaFibonacci<double, int> cola;

    // paso 3
    previo[raiz] = 0;
    distancias[raiz] = -1;

    // paso 5
    vector<ColaFibonacci<double, int>::Nodo*> nodos;
    vector<bool> extraido(n, false);
    nodos.reserve(n);

    // esto es heapify
    for (int i = 0; i < n; i++) {
        nodos.push_back(cola.agregar_par(distancias[i], i));
    }

    // paso 6
    while (!cola.vacio()) {
        int v = cola.extraer_minimo();
        extraido[v] = true;
        
        for (auto &vecino : grafo[v]) {
            int u = vecino.first;
            double dist_vu = vecino.second; 

            if (!extraido[u]) {
                if (distancias[v] + dist_vu < distancias[u]) {
                    distancias[u] = distancias[v] + dist_vu;
                    previo[u] = v;
                    cola.reducir_llave(nodos[u], distancias[v] + dist_vu);
                }
            }
        }
    }


}

} // namespace logs
