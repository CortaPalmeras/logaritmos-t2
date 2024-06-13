#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP


#include <vector>
namespace logs {

template <typename peso_t>
class Nodo {
    std::vector<std::pair<Nodo*, peso_t>> siguientes;
};

template <typename peso_t>
void dijkstra(Nodo<peso_t>* raiz);

} // namespace logs

#endif // !DIJKSTRA_HPP
