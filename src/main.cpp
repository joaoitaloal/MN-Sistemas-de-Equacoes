#include <iostream>
#include "Matrix/Matrix.h"

#include "Gauss/GaussNormal.h"
#include "Gauss/GaussJordan.h"

int main(){
    Matrix A({
        {2,  1,  1,  0},
        {4,  3,  3,  1},
        {8,  7,  9,  5},
        {6,  7,  9,  8}
    });
    Matrix B({
        {1},
        {2},
        {3},
        {4},
        {5}
    });
    
    cout << "MATRIZES INICIAIS" << endl << endl;
    cout << "A:" << endl;
    A.print();
    cout << endl;
    cout << "B:" << endl;
    B.print();
    cout << "----------------" << endl;
    GaussNormal gauss_normal(A, B);
    gauss_normal.eliminar_gauss();
    cout << "MATRIZES APÓS A APLICAÇÃO DO MÉTODO DE GAUSS" << endl << endl;
    cout << "A:" << endl;
    gauss_normal.print_mat();
    cout << endl;
    cout << "B:" << endl;
    gauss_normal.print_b();
    cout << "----------------" << endl;
    GaussJordan gauss_jordan(A, B);
    gauss_jordan.eliminar_gauss();
    cout << "MATRIZES APÓS A APLICAÇÃO DO MÉTODO DE GAUSS-JORDAN" << endl << endl;
    cout << "A:" << endl;
    gauss_jordan.print_mat();
    cout << endl;
    cout << "B:" << endl;
    gauss_jordan.print_b();

    return 0;
}