#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <utility>
#include <vector>

typedef std::vector<std::vector<std::pair<int, double>>> Grafo;

void dijkstra_fibonacci(int raiz, const Grafo& grafo, std::vector<int>& previo,
                        std::vector<double>& distancias);

void unir_nodos(Grafo& grafo, int nodo1, int nodo2, double peso);

Grafo crear_grafo(int i, int j);

#endif // !DIJKSTRA_HPP
