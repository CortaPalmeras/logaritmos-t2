#ifndef NODO_FIBONACCI_HPP
#define NODO_FIBONACCI_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>

namespace logs {

template <typename llave_t, typename valor_t>
class NodoFibonacci {
    public:
    NodoFibonacci<llave_t, valor_t>(llave_t llave, valor_t valor) : _hijos(0) {
        _llave = llave;
        _valor = valor;
        _marcado = false;

        _padre = nullptr;
        _hermano_i = nullptr;
        _hermano_d = nullptr;
    }

    unsigned int orden() const {
        return _hijos.size();
    }

    bool marcado() const {
        return _marcado;
    }

    void quitar_hijo(NodoFibonacci<llave_t, valor_t> *hijo) {
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

    NodoFibonacci<llave_t, valor_t> *operator+(NodoFibonacci<llave_t, valor_t> *otro) {
        anadir_hijo(otro);
        return this;
    }

    private:
    llave_t _llave;
    valor_t _valor;
    bool _marcado;

    NodoFibonacci<llave_t, valor_t> *_padre;
    NodoFibonacci<llave_t, valor_t> *_hermano_i;
    NodoFibonacci<llave_t, valor_t> *_hermano_d;
    std::vector<NodoFibonacci<llave_t, valor_t> *> _hijos;

    void quitar_hermanos() {
        _hermano_i->_hermano_d = _hermano_d;
        _hermano_d->_hermano_i = _hermano_i;

        _hermano_i = nullptr;
        _hermano_d = nullptr;
    }

    void anadir_hijo(NodoFibonacci<llave_t, valor_t> *hijo) {
        if (hijo->_padre != nullptr || hijo->_hermano_d != nullptr || hijo->_hermano_i != nullptr) {
            throw std::logic_error("Se intentó añadir un hijo que ya tiene padre o hermanos");
        }

        if (_hijos.empty()) {
            hijo->_hermano_i = hijo;
            hijo->_hermano_d = hijo;

        } else {
            NodoFibonacci<llave_t, valor_t> *ultimo = _hijos.back();
            hijo->_hermano_i = ultimo;
            ultimo->_hermano_d = hijo;

            NodoFibonacci<llave_t, valor_t> *primero = *(_hijos.begin());
            hijo->_hermano_d = primero;
            primero->_hermano_i = hijo;
        }

        hijo->_padre = this;
        _hijos.push_back(hijo);
    }
};

} // namespace logs

#endif // !NODO_FIBONACCI_HPP
//
