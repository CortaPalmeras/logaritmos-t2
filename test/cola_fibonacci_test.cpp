
#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "cola_fibonacci.hpp"

bool comparar_nodo(ColaFibonacci<double, unsigned int>::Nodo* a,
                   ColaFibonacci<double, unsigned int>::Nodo* b) {
    return a->llave() < b->llave();
}

void cola_fibonacci_test() {
    std::cout << "Tests para cola de Fibonacci: ";

    std::default_random_engine rng(56);
    std::uniform_real_distribution<double> dist_llave(-10, 10);
    std::uniform_int_distribution<unsigned int> dist_valor(0, 10);
    std::uniform_real_distribution<double> dist_decimal(0, 1);

    ColaFibonacci<double, unsigned int> cola;
    std::vector<ColaFibonacci<double, unsigned int>::Nodo*> nodos;
    std::vector<std::pair<double, unsigned int>> comparacion;
    nodos.reserve(10000);
    comparacion.reserve(10000);

    for (unsigned int i = 0; i < 10000; i++) {
        double llave = dist_llave(rng);
        unsigned int valor = dist_valor(rng);

        nodos.push_back(cola.agregarPar(llave, valor));
        comparacion.emplace_back(llave, valor);
    }

    for (unsigned int i = 0; i < nodos.size(); i += 5) {
        double nueva_llave =
            dist_decimal(rng) * (nodos[i]->llave() - dist_llave.a()) + dist_llave.a();

        cola.reducirLlave(nodos[i], nueva_llave);
        comparacion[i].first = nueva_llave;
    }

    std::sort(comparacion.begin(), comparacion.end());
    std::sort(nodos.begin(), nodos.end(), comparar_nodo);

    for (unsigned int i = 0; i < nodos.size() / 2; i++) {
        assert(comparacion[i].first == nodos[i]->llave());
        assert(comparacion[i].second == nodos[i]->valor());
        assert(comparacion[i].first == cola.llaveMenor());
        assert(comparacion[i].second == cola.valorMenor());
        assert(comparacion[i].second == cola.extraerMinimo());
    }

    nodos.erase(nodos.begin(), nodos.begin() + (nodos.size() / 2));
    comparacion.erase(comparacion.begin(), comparacion.begin() + (comparacion.size() / 2));

    for (unsigned int i = 0; i < comparacion.size(); i += 4) {
        double llave = dist_llave(rng);
        unsigned int valor = dist_valor(rng);
        nodos.push_back(cola.agregarPar(llave, valor));
        comparacion.emplace_back(llave, valor);

        double nueva_llave =
            dist_decimal(rng) * (nodos[i]->llave() - dist_llave.a()) + dist_llave.a();
        cola.reducirLlave(nodos[i], nueva_llave);
        comparacion[i].first = nueva_llave;
    }

    std::sort(comparacion.begin(), comparacion.end());
    std::sort(nodos.begin(), nodos.end(), comparar_nodo);

    for (unsigned int i = 0; i < nodos.size(); i++) {
        assert(comparacion[i].first == nodos[i]->llave());
        assert(comparacion[i].second == nodos[i]->valor());
        assert(comparacion[i].first == cola.llaveMenor());
        assert(comparacion[i].second == cola.valorMenor());
        assert(comparacion[i].second == cola.extraerMinimo());
    }

    std::cout << "\033[32m" << "Pasados" << "\033[0m" << std::endl;
}

