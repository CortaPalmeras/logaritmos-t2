
#include <vector>

#include "heap.hpp"

template <typename l, typename v>
Heap<l, v>::Nodo::Nodo(l llave, v valor, unsigned int pos) : _llave(llave), _valor(valor), _pos(pos){};

template <typename l, typename v>
l Heap<l, v>::Nodo::llave() {
    return _llave;
};

template <typename l, typename v>
v Heap<l, v>::Nodo::valor() {
    return _valor;
};

template <typename l, typename v>
Heap<l, v>::Heap() : _heap() {}

template <typename l, typename v>
bool Heap<l, v>::vacio() const {
    return _heap.empty();
}

template <typename l, typename v>
typename Heap<l, v>::Nodo* Heap<l, v>::agregarPar(l llave, v valor) {
    unsigned int pos = _heap.size();
    Nodo* nodo = new Nodo(llave, valor, pos);
    _heap.push_back(nodo);
    subir(pos);
    return nodo;
}

template <typename l, typename v>
l Heap<l, v>::llaveMenor() const {
    return _heap[0]->_llave;
}

template <typename l, typename v>
v Heap<l, v>::valorMenor() const {
    return _heap[0]->_valor;
}

template <typename l, typename v>
void Heap<l, v>::intercambiar(unsigned int i, unsigned int j) {
    Nodo* tmp = _heap[i];

    _heap[i] = _heap[j];
    _heap[j] = tmp;

    _heap[i]->_pos = i;
    _heap[j]->_pos = j;
}

template <typename l, typename v>
void Heap<l, v>::subir(unsigned int indice) {
    while (indice > 0) {
        unsigned int indice_padre = (indice - 1) / 2;

        if (_heap[indice_padre]->_llave < _heap[indice]->_llave) {
            break;
        }

        intercambiar(indice, indice_padre);
        indice = indice_padre;
    }
}

template <typename l, typename v>
void Heap<l, v>::bajar(unsigned int indice) {
    unsigned int n = _heap.size();
    Nodo* nodo = _heap[indice];

    while (true) {
        unsigned int ind_hijo_i = 2 * nodo->_pos + 1;
        unsigned int ind_hijo_d = ind_hijo_i + 1;

        if (ind_hijo_d < n) {
            unsigned int ind_hijo_menor;

            if (_heap[ind_hijo_i]->_llave < _heap[ind_hijo_d]->_llave) {
                ind_hijo_menor = ind_hijo_i;
            } else {
                ind_hijo_menor = ind_hijo_d;
            }

            Nodo* hijo_menor = _heap[ind_hijo_menor];

            if (nodo->_llave > hijo_menor->_llave) {
                intercambiar(nodo->_pos, ind_hijo_menor);
            } else {
                break;
            }

        } else if (ind_hijo_i < n) {
            Nodo* hijo_i = _heap[ind_hijo_i];

            if (nodo->_llave > hijo_i->_llave) {
                intercambiar(nodo->_pos, ind_hijo_i);
            } else {
                break;
            }

        } else {
            break;
        }
    }
}

template <typename l, typename v>
v Heap<l, v>::extraerMinimo() {
    v ret = _heap[0]->_valor;
    intercambiar(0, _heap.size() - 1);

    delete _heap[_heap.size() - 1];
    _heap.erase(_heap.end() - 1);

    if (!_heap.empty()) {
        bajar(0);
    }
    return ret;
}

template <typename l, typename v>
void Heap<l, v>::reducirLlave(Nodo* nodo, l llave) {
    nodo->_llave = llave;
    subir(nodo->_pos);
}

template class Heap<double, unsigned int>;

