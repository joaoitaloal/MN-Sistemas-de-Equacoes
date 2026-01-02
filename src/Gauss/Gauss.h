#ifndef MN_GAUSS_H
#define MN_GAUSS_H

#include "../Matrix/Matrix.h"
#include <stdexcept> 

class Gauss {
    public:
        Gauss(Matrix m, Matrix b);
        
        double eliminar_gauss();

        void print_mat();
        void print_b();
    protected:
        virtual void iterar(int i) = 0;

        Matrix mat;
        Matrix b;

};

#endif // MN_GAUSS_H