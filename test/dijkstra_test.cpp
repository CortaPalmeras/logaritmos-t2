
#include <cassert>
#include <iostream>
#include <vector>

#include "dijkstra.hpp"

using std::vector;

void dijkstra_test() {
    std::cout << "Tests para dijkstra con cola de fibonacci: ";

    Grafo grafo(11);

    unir_nodos(grafo, 0, 1, 6);
    unir_nodos(grafo, 0, 2, 8);

    unir_nodos(grafo, 1, 3, 5);
    unir_nodos(grafo, 1, 7, 4);

    unir_nodos(grafo, 2, 3, 1);
    unir_nodos(grafo, 2, 10, 2);

    unir_nodos(grafo, 3, 4, 2);
    unir_nodos(grafo, 3, 5, 4);
    unir_nodos(grafo, 3, 7, 2);

    unir_nodos(grafo, 4, 5, 10);
    unir_nodos(grafo, 4, 9, 9);
    unir_nodos(grafo, 4, 10, 10);

    unir_nodos(grafo, 5, 6, 7);
    unir_nodos(grafo, 5, 7, 10);
    unir_nodos(grafo, 5, 8, 10);
    unir_nodos(grafo, 5, 9, 3);

    unir_nodos(grafo, 6, 7, 4);
    unir_nodos(grafo, 6, 8, 9);

    unir_nodos(grafo, 8, 9, 5);

    int raiz = 3;
    vector<int> previo;
    vector<double> distancias;

    dijkstra_fibonacci(raiz, grafo, previo, distancias);

    vector<int> previo_esperado({2, 3, 3, -1, 3, 3, 7, 3, 9, 5, 2});
    vector<double> distancias_esperado({9, 5, 1, 0, 2, 4, 6, 2, 12, 7, 3});

    assert(previo == previo_esperado);
    assert(distancias == distancias_esperado);

    std::cout << "\033[32m" << "Pasados" << "\033[0m" << std::endl;
}
