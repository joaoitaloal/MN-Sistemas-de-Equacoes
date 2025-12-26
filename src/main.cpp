#include <iostream>
#include "Matriz/Matriz.h"

int main(){
    Matrix A({
        {0,  0,  0,  0,  0},
        {0,  2,  1,  1,  0},
        {0,  4,  3,  3,  1},
        {0,  8,  7,  9,  5},
        {0,  6,  7,  9,  8}
    });
    Matrix B({
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5}
    });
    
    cout << "MATRIZES INICIAIS" << endl << endl;
    cout << "A:" << endl;
    A.print();
    cout << endl;
    cout << "B:" << endl;
    B.print();
    cout << "----------------" << endl;
    //gauss(A, B);
    cout << "MATRIZES APÓS A APLICAÇÃO DO MÉTODO DE GAUSS" << endl << endl;
    cout << "A:" << endl;
    A.print();
    cout << endl;
    cout << "B:" << endl;
    B.print();
    cout << "----------------" << endl;
    //gauss_jordan(A, B);
    cout << "MATRIZES APÓS A APLICAÇÃO DO MÉTODO DE GAUSS-JORDAN" << endl << endl;
    cout << "A:" << endl;
    A.print();
    cout << endl;
    cout << "B:" << endl;
    B.print();

    return 0;
}