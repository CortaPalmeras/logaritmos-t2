#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <utility>
#include <vector>

namespace logs {

using std::vector, std::pair;

template <typename peso_t>
void dijkstra(int raiz, vector<vector<pair<int, peso_t>>> const &grafo);

} // namespace logs

#endif // !DIJKSTRA_HPP
