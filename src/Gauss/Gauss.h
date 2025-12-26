#ifndef MN_GAUSS_H
#define MN_GAUSS_H

#include <vector>
#include "../Matrix/Matrix.h"

class Gauss {
    public:
        Gauss(Matrix m, vector <double> b);
        
        void eliminar_gauss();
        virtual void iterar(int i, double x) = 0;
    protected:
        Matrix mat;
        std::vector <double> b;
};

#endif // MN_GAUSS_H