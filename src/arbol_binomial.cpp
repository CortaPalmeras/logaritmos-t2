
#include <vector>
#include <algorithm>

#include "tarea.hpp"

using namespace std;

class ArbolBinomial {
    public:

    int orden;
    Par raiz;
    vector<ArbolBinomial> arboles;


    ArbolBinomial *crearArbol(int orden, vector<Par> pares) {

        ArbolBinomial *AB = new ArbolBinomial;
        auto minimo = min_element(pares.begin(), pares.end());
        int indice_minimo = minimo - pares.begin();

        AB->orden = orden;
        AB->raiz = *minimo;

        pares.erase(pares.begin() + indice_minimo);

        for (int i = pares.size(); i > 0; i--) {
            ArbolBinomial *hijo = crearArbol(i, pares);
            AB->arboles.push_back(*hijo);
        }

        return AB;
    }
};
