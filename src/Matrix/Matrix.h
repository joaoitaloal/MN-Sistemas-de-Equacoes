#ifndef MN_MATRIX_H
#define MN_MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

#define PRINT_PRECISION_MATRIX 3
#define PRINT_W_VALUES 8

using namespace std;

class Matrix {
    public:
        Matrix(int s);
        Matrix(int s, int t);
        // Copia todo o vetor de entrada
        Matrix(vector <vector <double>> matrix_);

        //void switch_col(int x, int y);
        void switch_row(int x, int y);

        void change_col(int x, Matrix column);

        pair<int, int> get_size();

        double at(int x, int y);
        void set(int x, int y, double val);

        void print();

    protected:
        vector <vector <double>> matrix;
        pair<int, int> matrix_size;

};

#endif // MN_MATRIX_H
