#ifndef MATRIZ
#define MATRIZ

#include <vector>

class Matriz {
    public:
        Matriz(int n);
        int size();
        void switch_col(int x, int y);
        void switch_row(int x, int y);
    protected:
        std::vector <std::vector <double>> m;
        int size;
};

#endif