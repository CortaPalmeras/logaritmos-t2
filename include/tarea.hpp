#ifndef TAREA_HPP
#define TAREA_HPP

namespace logs {

struct nodo;
struct arista;
struct par;

typedef struct nodo {
    struct par *par;
} Nodo;

typedef struct arista {
    Nodo nodo1;
    Nodo nodo2;
    int peso;
} Arista;

typedef struct par {
    int distancia;
    Nodo *nodo;
} Par;

} // namespace logs

#endif // !TAREA_HPP
