
#include <algorithm>
#include <ostream>
#include <random>
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

#include "dijkstra.hpp"
#include "cola_fibonacci.hpp"
#include "heap.hpp"

using namespace std;


template <typename Cola>
bool comparar_nodo(typename Cola::Nodo* a, typename Cola::Nodo* b) {
    return a->llave() < b->llave();
}

template <typename Cola>
void test_cola_definido() {
    Cola cola;
    vector<typename Cola::Nodo*> nodos;

    // test general

    for (int i = 0; i < 10; i++) {
        nodos.push_back(cola.agregarPar(i, i));
    }

    assert(cola.extraerMinimo() == 0);

    cola.reducirLlave(nodos[4], 0);
    cola.reducirLlave(nodos[1], -1);

    assert(cola.extraerMinimo() == 1);
    assert(cola.extraerMinimo() == 4);

    cola.reducirLlave(nodos[3], 2);

    unsigned int valor2o3 = cola.extraerMinimo();
    
    assert(valor2o3 == 2 || valor2o3 == 3);

    if (valor2o3 == 2) {
        assert(cola.extraerMinimo());
    } else {
        assert(cola.extraerMinimo());
    }

    cola.reducirLlave(nodos[6], 1);
    cola.reducirLlave(nodos[8], 7);
    cola.reducirLlave(nodos[9], 2.5);

    assert(cola.extraerMinimo() == 6);
    assert(cola.extraerMinimo() == 9);
    assert(cola.extraerMinimo() == 5);
    assert(cola.extraerMinimo() == 8);
    assert(cola.extraerMinimo() == 7);

    assert(cola.vacio());

    // Test con todas las llaves iguales
    nodos.clear();
    for (int i = 0; i < 10; i++) {
        nodos.push_back(cola.agregarPar(5, i));
    }

    vector<int> extraido(10, 0);

    unsigned int valor_extraido = cola.extraerMinimo();
    extraido[valor_extraido]++;
    valor_extraido = cola.extraerMinimo();
    extraido[valor_extraido]++;

    unsigned int no_extraido1 = 0;
    while (extraido[no_extraido1]) {
        no_extraido1++;
    }

    unsigned int no_extraido2 = no_extraido1 + 1;;
    while (extraido[no_extraido2]) {
        no_extraido2++;
    }

    cola.reducirLlave(nodos[no_extraido1], 3);
    cola.reducirLlave(nodos[no_extraido2], 1);

    valor_extraido = cola.extraerMinimo();
    assert(valor_extraido == no_extraido2);
    extraido[valor_extraido]++;

    valor_extraido = cola.extraerMinimo();
    assert(valor_extraido == no_extraido1);
    extraido[valor_extraido]++;

    valor_extraido = cola.extraerMinimo();
    extraido[valor_extraido]++;
    valor_extraido = cola.extraerMinimo();
    extraido[valor_extraido]++;

    while (extraido[no_extraido1]) {
        no_extraido1++;
    }

    no_extraido2 = no_extraido1 + 1;;
    while (extraido[no_extraido2]) {
        no_extraido2++;
    }

    cola.reducirLlave(nodos[no_extraido1], 3);
    valor_extraido = cola.extraerMinimo();
    assert(valor_extraido == no_extraido1);
    extraido[valor_extraido]++;

    cola.reducirLlave(nodos[no_extraido2], 3);
    valor_extraido = cola.extraerMinimo();
    assert(valor_extraido == no_extraido2);
    extraido[valor_extraido]++;

    valor_extraido = cola.extraerMinimo();
    extraido[valor_extraido]++;
    valor_extraido = cola.extraerMinimo();
    extraido[valor_extraido]++;

    for (int i = 0; i < 10; i++) {
        assert(extraido[i] == 1);
    }

    assert(cola.vacio());
}

template <typename Cola>
void test_cola_aleatorio() {
    default_random_engine rng(56);
    uniform_real_distribution<double> dist_llave(-100, 100);
    uniform_int_distribution<unsigned int> dist_valor(0, 100000);
    uniform_real_distribution<double> dist_decimal(0, 1);

    Cola cola;
    vector<typename Cola::Nodo*> nodos;
    vector<pair<double, unsigned int>> comparacion;
    nodos.reserve(10000);
    comparacion.reserve(10000);

    // test solo con insercion de valores
    for (unsigned int i = 0; i < 10000; i++) {
        double llave = dist_llave(rng);
        unsigned int valor = dist_valor(rng);

        nodos.push_back(cola.agregarPar(llave, valor));
        comparacion.emplace_back(llave, valor);
    }

    sort(comparacion.begin(), comparacion.end());
    sort(nodos.begin(), nodos.end(), comparar_nodo<Cola>);

    for (unsigned int i = 0; i < nodos.size() / 2; i++) {
        assert(comparacion[i].first == nodos[i]->llave());
        assert(comparacion[i].second == nodos[i]->valor());
        assert(comparacion[i].first == cola.llaveMenor());
        assert(comparacion[i].second == cola.valorMenor());
        assert(comparacion[i].second == cola.extraerMinimo());
    }

    nodos.erase(nodos.begin(), nodos.begin() + (nodos.size() / 2));
    comparacion.erase(comparacion.begin(), comparacion.begin() + (comparacion.size() / 2));

    // Test con reducción de llaves
    for (unsigned int i = 0; i < 5000; i++) {
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

    sort(comparacion.begin(), comparacion.end());
    sort(nodos.begin(), nodos.end(), comparar_nodo<Cola>);

    for (unsigned int i = 0; i < nodos.size() / 2; i++) {
        assert(comparacion[i].first == nodos[i]->llave());
        assert(comparacion[i].second == nodos[i]->valor());
        assert(comparacion[i].first == cola.llaveMenor());
        assert(comparacion[i].second == cola.valorMenor());
        assert(comparacion[i].second == cola.extraerMinimo());
    }

    nodos.erase(nodos.begin(), nodos.begin() + (nodos.size() / 2));
    comparacion.erase(comparacion.begin(), comparacion.begin() + (comparacion.size() / 2));

    // Test añadiendo y reduciendo llaves al mismo tiempo
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

    sort(comparacion.begin(), comparacion.end());
    sort(nodos.begin(), nodos.end(), comparar_nodo<Cola>);

    for (unsigned int i = 0; i < nodos.size(); i++) {
        assert(comparacion[i].first == nodos[i]->llave());
        assert(comparacion[i].second == nodos[i]->valor());
        assert(comparacion[i].first == cola.llaveMenor());
        assert(comparacion[i].second == cola.valorMenor());
        assert(comparacion[i].second == cola.extraerMinimo());
    }
}

template <typename Cola>
void test_dijkstra_predefinidos() {
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

    dijkstra<Cola>(raiz, grafo, previo, distancias);

    vector<int> previo_esperado({2, 3, 3, -1, 3, 3, 7, 3, 9, 5, 2});
    vector<double> distancias_esperado({9, 5, 1, 0, 2, 4, 6, 2, 12, 7, 3});

    assert(previo == previo_esperado);
    assert(distancias == distancias_esperado);
}

template <typename Cola>
void test_dijkstra_aleatorios() {
    Grafo grafo = crear_grafo(10, 18);

    unsigned int raiz = 0;
    vector<int> previo;
    vector<double> distancias;

    dijkstra<Cola>(raiz, grafo, previo, distancias);

    vector<bool> validos(previo.size(), false);

    queue<int> validacion;

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


int main(void) {
    cout << "Test para Cola de Fibonacci: " << flush;
    test_cola_definido<ColaFibonacci<double, unsigned int>>();
    test_cola_aleatorio<ColaFibonacci<double, unsigned int>>();
    cout << "Pasado" << endl;

    cout << "Test para heap: " << flush;
    test_cola_definido<Heap<double, unsigned int>>();
    test_cola_aleatorio<Heap<double, unsigned int>>();
    cout << "Pasado" << endl;

    cout << "Test algoritmo de Dijkstra con cola de Fibonacci: " << flush;
    test_dijkstra_aleatorios<ColaFibonacci<double, unsigned int>>();
    test_dijkstra_predefinidos<ColaFibonacci<double, unsigned int>>();
    cout << "Pasado" << endl;

    cout << "Test algoritmo de Dijkstra con heap: " << flush;
    test_dijkstra_aleatorios<Heap<double, unsigned int>>();
    test_dijkstra_predefinidos<Heap<double, unsigned int>>();
    cout << "Pasado" << endl;

    return 0;
}

