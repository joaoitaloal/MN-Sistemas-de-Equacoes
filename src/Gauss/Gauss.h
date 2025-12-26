#ifndef GAUSS
#define GAUSS

#include <vector>
#include "../Matrix/Matrix.h"

class Gauss {
    public:
        Gauss(Matrix m, vector <double> b);
        
        void eliminar_gauss();
        void iterar(int i, float x);
    protected:
        Matrix mat;
        std::vector <double> b;
};

#endif 