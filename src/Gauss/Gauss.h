#ifndef GAUSS
#define GAUSS

#include <vector>
#include "../Matrix/Matrix.h"

class Gauss {
    public:
        Gauss(Matrix m, vector <double> b);
        
        void eliminar_gauss();
        virtual void iterar(int i, float x) = 0;
    protected:
        Matrix mat;
        std::vector <double> b;
};

#endif 