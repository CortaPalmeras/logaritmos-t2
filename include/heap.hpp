#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

namespace logs {

class Heap {
    private:

    struct par;

    typedef struct nodo {
        struct par *par;
    } Nodo;

    typedef struct arista {
        par* nodo1;
        par* nodo2;
        int peso;
    } Arista;

    typedef struct par {
        int distancia;
        par *nodo;
    } Par;

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
