#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

#include "tarea.hpp"

namespace logs {

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

} // namespace logs

#endif // !HEAP_HPP
