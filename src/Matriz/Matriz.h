#ifndef MN_MATRIX_H
#define MN_MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

#define PRINT_PRECISION_MATRIX 3
#define PRINT_W_VALUES 8

using namespace std;

class Matriz {
    public:
        Matriz(int s);
        Matriz(int s, int t);

        pair<int, int> get_size();

        double at(int x, int y);
        void set(int x, int y, double val);

        void print();

    protected:
        std::vector <std::vector <double>> matrix;
        pair<int, int> matrix_size;

        //void switch_col(int x, int y);
        void switch_row(int x, int y);
};

#endif // MN_MATRIX_H