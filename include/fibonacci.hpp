#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include "tarea.hpp"
#include "nodo_fibonacci.hpp"

namespace logs {

class ColaFibonacci{
    vector <ArbolBinomial>arboles;
    ArbolBinomial minimo;

    int hayArboles=0;

    void AgregarPar(int distancia, Nodo *nodo);

    Par *ExtraerMinimo();

    void DecreaseKey(Nodo nodo, int nuevaDistancia);
};

} // namespace logs

#endif // !FIBONACCI_HPP
