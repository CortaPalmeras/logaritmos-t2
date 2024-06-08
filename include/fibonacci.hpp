#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include "nodo_fibonacci.hpp"
#include "tarea.hpp"

namespace logs {

template <typename llave_t, typename valor_t>
class ColaFibonacci {
private:
    class Nodo;
    Nodo *minimo;

    NodoFibonacci<llave_t, valor_t> *raiz_minima;

    NodoFibonacci<llave_t, valor_t> *AgregarPar(llave_t, valor_t);

    std::pair<llave_t, valor_t> ExtraerMinimo();

    void DecreaseKey(NodoFibonacci<llave_t, valor_t> *nodo, llave_t llave);
};

template <typename llave_t, typename valor_t>
class ColaFibonacci<llave_t, valor_t>::Nodo {
private:
    llave_t _llave;
    valor_t _valor;
    bool _marcado;

    Nodo *_padre;
    Nodo *_hermano_i;
    Nodo *_hermano_d;
    std::vector<Nodo *> _hijos;

    void quitar_hermanos() {
        _hermano_i->_hermano_d = _hermano_d;
        _hermano_d->_hermano_i = _hermano_i;

        _hermano_i = nullptr;
        _hermano_d = nullptr;
    }

    void anadir_hijo(Nodo *hijo) {
        if (hijo->_padre != nullptr || hijo->_hermano_d != nullptr || hijo->_hermano_i != nullptr) {
            throw std::logic_error("Se intentó añadir un hijo que ya tiene padre o hermanos");
        }

        if (_hijos.empty()) {
            hijo->_hermano_i = hijo;
            hijo->_hermano_d = hijo;

        } else {
            Nodo *ultimo = _hijos.back();
            hijo->_hermano_i = ultimo;
            ultimo->_hermano_d = hijo;

            Nodo *primero = *(_hijos.begin());
            hijo->_hermano_d = primero;
            primero->_hermano_i = hijo;
        }

        hijo->_padre = this;
        _hijos.push_back(hijo);
    }

public:
    Nodo(llave_t llave, valor_t valor): 
        _hijos(0), _llave(llave), _valor(valor), 
        _marcado(false), _padre(nullptr),
        _hermano_i(nullptr), _hermano_d(nullptr) {}

    unsigned int orden() const {
        return _hijos.size();
    }

    bool marcado() const {
        return _marcado;
    }

    void quitar_hijo(Nodo *hijo) {
        if (_hijos.empty()) {
            throw std::logic_error("Se intentó eliminar un nodo de un padre que no tiene hijos");
        } else if (hijo->_padre != nullptr) {
            throw std::logic_error(
                "Se intentó eliminar un nodo de un nodo padre sin que sea su hijo");
        } else if (_marcado) {
            throw std::logic_error(
                "Se intentó eliminar un nodo de un nodo padre que ya estaba marcado");
        }

        hijo->quitar_hermanos();
        hijo->_padre = nullptr;

        _marcado = true;
        _hijos.erase(std::remove(_hijos.begin(), _hijos.end(), hijo), _hijos.end());
    }

    void quitar_de_arbol() {
        if (_padre != nullptr) {
            _padre->quitar_hijo(this);
        } else if (_hermano_d != nullptr && _hermano_i != nullptr) {
            quitar_hermanos();
        } else {
            throw std::logic_error("Se intentó quitar de un arbol a un nodo sin vecinos");
        }
    }

    Nodo *operator+(Nodo *otro) {
        anadir_hijo(otro);
        return this;
    }
};

} // namespace logs

#endif // !FIBONACCI_HPP
