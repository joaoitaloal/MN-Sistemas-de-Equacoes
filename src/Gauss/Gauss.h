#ifndef GAUSS
#define GAUSS

#include <vector>
#include "../Matriz/Matriz.h"

class Gauss {
    public:
        Gauss(Matriz m, vector <double> b);
        
        void eliminar_gauss();
        void iterar(int i, float x);
    protected:
        Matriz mat;
        std::vector <double> b;
};

#endif 