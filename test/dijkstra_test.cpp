
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

#include "dijkstra.hpp"

using std::vector;

void test_valores_predefinidos() {
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

    unsigned int raiz = 3;
    vector<int> previo;
    vector<double> distancias;

    dijkstra_fibonacci(raiz, grafo, previo, distancias);

    vector<int> previo_esperado({2, 3, 3, -1, 3, 3, 7, 3, 9, 5, 2});
    vector<double> distancias_esperado({9, 5, 1, 0, 2, 4, 6, 2, 12, 7, 3});

    assert(previo == previo_esperado);
    assert(distancias == distancias_esperado);
}

void test_valores_aleatorios() {
    Grafo grafo = crear_grafo(10, 18);

    unsigned int raiz = 0;
    vector<int> previo;
    vector<double> distancias;

    dijkstra_fibonacci(raiz, grafo, previo, distancias);

    vector<bool> validos(previo.size(), false);

    std::queue<int> validacion;

    for (unsigned int i = 1; i < previo.size(); i++) {
        validacion.push(i);
    }

    assert(previo[0] == -1);
    validos[0] = true;

    long iteraciones = 0;
    long limite = previo.size() * previo.size();

    while (!validacion.empty() && iteraciones < limite) {
        int item = validacion.front();
        validacion.pop();

        if (validos[previo[item]]) {
            validos[item] = true;
        } else {
            validacion.push(item);
        }

        iteraciones++;
    }

    assert(iteraciones != limite);

    for (unsigned int i = 0; i < validos.size(); i++) {
        assert(validos[i]);
    }
}

void dijkstra_test() {
    std::cout << "Tests para dijkstra con cola de fibonacci: ";

    test_valores_predefinidos();
    test_valores_aleatorios();

    std::cout << "\033[32m" << "Pasados" << "\033[0m" << std::endl;
}

