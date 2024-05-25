#ifndef HEAP
#define HEAP

#include <vector>

#include "tarea.hpp"

class Heap {
    private:
    std::vector<Par> pares;
    int tamaño = 0;

    public:
    void AgregarPar(int distancia, Nodo *nodo);

    void Subir();

    void Bajar();

    Par *ExtraerMinimo();

    void DecreaseKey(Nodo nodo, int nuevaDistancia);
};

#endif // !HEAP
