#ifndef MN_GAUSS_H
#define MN_GAUSS_H

#include <vector>
#include "../Matrix/Matrix.h"

class Gauss {
    public:
        Gauss(Matrix m, Matrix b);
        
        void eliminar_gauss();
        virtual void iterar(int i, double x) = 0;
    protected:
        Matrix mat;
        Matrix b;
};

#endif // MN_GAUSS_H