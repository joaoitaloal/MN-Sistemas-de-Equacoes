#ifndef GAUSS
#define GAUSS

#include <vector>

class Gauss {
    public:
        Gauss(std::vector<std::vector<float>> m, std::vector<float> b);
        
        void iterar();
        std::vector<float> get_solucao();
    protected:
        std::vector<std::vector<float>> m;
        std::vector<float> b;
        std::vector<float> solucao;
};

#endif 