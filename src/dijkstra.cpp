
#include <limits>
#include <vector>

namespace logs {

template <typename peso_t>
class Nodo {
    std::vector<std::pair<Nodo*, peso_t>> siguientes;
};

template <typename peso_t>
void dijkstra(Nodo<peso_t>* raiz) {
}

template <typename cola_prioridad>
vector<int> dijkstra(int inicio, const vector<vector<std::pair<int, int>>> &grafo) {
    int n = grafo.size();
    vector<int> dist(n, std::numeric_limits<int>::max());
    dist[inicio] = 0;

    cola_prioridad pq;
    pq.push({0, inicio});

    while (!pq.empty()) {
        int d = pq.peek_prio();
        int u = pq.pop();

        if (d > dist[u])
            continue;

        for (const auto &neighbor : grafo[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

} // namespace logs
