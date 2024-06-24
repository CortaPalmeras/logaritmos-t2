#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

template <typename llave_t, typename valor_t>
class Heap {
public:
    class Nodo;
    Heap();

    // Agrega un valor con una cierta prioridad al heap
    // y devuelve una referencia al nodo correspondiente
    Nodo* agregarPar(llave_t llave, valor_t valor);

    // Devuelve la llave y valor menor
    // sin sacarlos del heap
    llave_t llaveMenor() const;
    valor_t valorMenor() const;

    // devuelve true si el heap está vacío
    bool vacio() const;

    // Devuelve el valor con la prioridad mas baja,
    // quitando el nodo del heap
    valor_t extraerMinimo();

    // Reduce la prioridad de un cierto nodo
    void reducirLlave(Nodo* nodo, llave_t llave);

private:
    std::vector<Nodo*> _heap;

    void intercambiar(unsigned int i, unsigned int j);

    void subir(unsigned int indice);

    void bajar(unsigned int indice);
};

template <typename llave_t, typename valor_t>
class Heap<llave_t, valor_t>::Nodo {
public:
    llave_t llave();
    valor_t valor();

private:
    friend Heap;

    Nodo(llave_t llave, valor_t valor, unsigned int pos);
    Nodo() = delete;

    llave_t _llave;
    const valor_t _valor;

    unsigned int _pos;
};

#endif // !HEAP_HPP
