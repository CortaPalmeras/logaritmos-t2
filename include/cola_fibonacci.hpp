#ifndef COLA_FIBONACCI_HPP
#define COLA_FIBONACCI_HPP

namespace logs {

template <typename llave_t, typename valor_t>
class ColaFibonacci {
public:
    class Nodo;
    ColaFibonacci();

    // Agrega un valor con una cierta prioridad al heap
    // y devuelve una referencia al nodo correspondiente
    Nodo *agregar_par(llave_t llave, valor_t valor);

    // Devuelve la llave y valor menor
    // sin sacarlos del heap
    llave_t llave_menor() const;
    valor_t valor_menor() const;

    // devuelve true si el heap está vacío
    bool vacio() const;

    // Devuelve el valor con la prioridad mas baja,
    // quitando el nodo del heap
    valor_t extraer_minimo();

    // Reduce la prioridad de un cierto nodo
    void reducir_llave(Nodo *nodo, llave_t llave);


private:
    Nodo *_minimo;
    long _tamano;

    // mueve un nodo a la raiz del heap, asume que el input no es una raiz,
    // checkear antes de llamar o va a tirar segfault :D
    void mover_a_raiz(Nodo *nodo);

    void consolidar();
};

template <typename llave_t, typename valor_t>
class ColaFibonacci<llave_t, valor_t>::Nodo {
public:
    llave_t llave();
    valor_t valor();

private:
    friend ColaFibonacci;

    Nodo(llave_t llave, valor_t valor);
    Nodo() = delete;

    void anadir_hijo(Nodo *nuevo_hijo);

    llave_t _llave;
    const valor_t _valor;
    bool _marcado;
    unsigned int _orden;

    Nodo *_padre;
    Nodo *_hijo;
    Nodo *_hermano_i;
    Nodo *_hermano_d;
};

} // namespace logs

#include "cola_fibonacci_impl.hpp"

#endif // !COLA_FIBONACCI_HPP
