#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <utility>
#include <vector>

typedef std::vector<std::vector<std::pair<unsigned int, double>>> Grafo;

template <typename Cola>
void dijkstra(unsigned int raiz, const Grafo& grafo, std::vector<int>& previo,
                        std::vector<double>& distancias);

void unir_nodos(Grafo& grafo, unsigned int nodo1, unsigned int nodo2, double peso);

Grafo crear_grafo(unsigned int i, unsigned int j);

#endif // !DIJKSTRA_HPP
