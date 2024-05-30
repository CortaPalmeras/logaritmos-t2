#include <iostream>
#include <vector>
#include <limits>

using namespace std;


template <typename cola_prioridad>
vector<int> dijkstra(int source, const vector<vector<pair<int,int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[source] = 0;

    cola_prioridad pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.peek_prio();
        int u = pq.pop();

        // If this distance is greater than the currently known distance, skip it
        if (d > dist[u]) continue;

        // Explore all neighbors of vertex u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relax the edge (u, v)
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

