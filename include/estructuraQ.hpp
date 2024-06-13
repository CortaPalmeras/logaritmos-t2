#ifndef ESTRUCTURAQ_H
#define ESTRUCTURAQ_H

#include "tarea.hpp"
#include <utility>

class estructuraQ {
public:
    using Par = logs::Par;
    using Nodo = logs::Nodo;

    virtual Par ExtraerMinimo() = 0;
    virtual void AgregarPar(int distancia, Nodo *nodo) = 0;
    virtual void DecreaseKey(Nodo nodo, int nuevaDistancia) = 0;

    virtual ~estructuraQ() = default;
};

#endif // ESTRUCTURAQ_H
