
#include <iostream>
#include <vector>

class outer {
private:
    class privinner {
    private:
        int val;

    public:
        privinner(int v) : val(v) {}
        privinner() = delete;
        void print() {
            std::cout << "print private inner " << val << std::endl;
        }
    };

    class privref {
    private:
        privinner *ptr;
        privref(privinner *p) : ptr(p) {}
        privref() = delete;
        friend outer;
    };

    privinner pr;

public:
    class pubinner {
    private:
        int val;

    public:
        pubinner(int v) : val(v) {}
        pubinner() = delete;
        void print() {
            std::cout << "print public inner " << val << std::endl;
        }
    };

    pubinner pu;

    privinner *getpr() {
        return &pr;
    }

    pubinner *getpu() {
        return &pu;
    }

    privref getpref() {
        return privref(&pr);
    }

    void printpref(privref ref) {
        ref.ptr->print();
    }

    outer(int puv, int prv) : pr(prv), pu(puv) {}
};

void llenar_vector(std::vector<int> v) {
    v = std::vector(1000, 8);
}

int main(void) {
    outer *o = new outer(3, 5);

    // esto se puede hacer
    o->getpu()->print();
    outer::pubinner pub(7);
    pub.print();

    // esto se puede hacer por algun motivo (wtf)
    o->getpr()->print();

    // esto no se puede hacer porque outer::privinner es una clase privada
    // outer::privinner priv(7);
    // priv.print();

    // esto no se puede hacer porque el constructor por defecto no existe
    // std::vector<outer> vout(5);

    // esto no se puede hacer porque el constructor por defecto fue explicitamente eliminado
    // std::vector<outer::pubinner> vpub(5);

    // esto no se puede hacer porque outer::privinner es una clase privada
    // std::vector<outer::privinner> vpriv(5);


    return 0;
}
