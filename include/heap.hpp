#ifndef HEAP
#define HEAP

#include <vector>

struct nodo;
struct arista;
struct par;

typedef struct nodo {
    struct par *par;
} Nodo;

typedef struct arista{
    Nodo nodo1;
    Nodo nodo2;
    int peso;
} Arista;

typedef struct par {
    int distancia;
    Nodo *nodo;
} Par;

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
