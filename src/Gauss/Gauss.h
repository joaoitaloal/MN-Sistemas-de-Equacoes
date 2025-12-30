#ifndef MN_GAUSS_H
#define MN_GAUSS_H

#include "../Matrix/Matrix.h"
#include <math.h>

class Gauss {
    public:
        Gauss(Matrix m, Matrix b);
        
        double eliminar_gauss();

        void print_mat();
        void print_b();

    protected:
        Matrix mat;
        Matrix b;

        virtual int ini_intervalo(int i);

};

#endif // MN_GAUSS_H