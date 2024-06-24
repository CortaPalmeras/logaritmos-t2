
#include <fstream>
#include <chrono>

#include "dijkstra.hpp"
#include "cola_fibonacci.hpp"

using namespace std;

int main(void) {
    ofstream archivo("dijkstra.csv");

    archivo << "cantidad_nodos,cantidad_aristas,t_con_fib,t_con_heap" << endl;

    for (int i = 10; i <= 14; i+=2) {
        for (int j = 16; j <= 22; j++) {
            for (int n = 0; n < 50; n++) {
                Grafo grafo = crear_grafo(i, j);

                archivo << i << ',' << j << ',';

                vector<int> previo;
                vector<double> distancias;

                auto ini = chrono::high_resolution_clock::now();
                dijkstra<ColaFibonacci<double, unsigned int>>(0, grafo, previo, distancias);
                auto fin = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> dif = fin - ini;
                archivo << dif.count() << ',';
                
                previo.clear();
                distancias.clear();

                ini = chrono::high_resolution_clock::now();
                /*dijkstra_heap(0, grafo, previo, distancias);*/
                fin = std::chrono::high_resolution_clock::now();

                dif = fin - ini;
                archivo << dif.count() << endl;
            }
        }
    }

    archivo.close();
}
