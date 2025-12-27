#include "Gauss.h"

Gauss::Gauss(Matrix m, Matrix b)
: mat(m), b(b) {}

double Gauss::eliminar_gauss(){
    std::pair<int, int> p = mat.get_size();
    int n = p.first;
    int num_trocas = 0;

    for (int i=0; i < n; i++){
        // pivotação
        int maior = i;
        
        for(int j = i + 1; j < n; ++j){
            if (mat.abs(mat.at(j, i)) > mat.abs(mat.at(maior, i))) maior = j;
        }

        if (maior != i){
            num_trocas++;
            mat.switch_row(i, maior);
        }

        iterar(i);
    }

    double determin;
    if(num_trocas % 2 == 0) determin = 1;
    else determin = -1;

    for(int i = 0; i < n; i++) determin *= mat.at(i, i);
    return determin;
}

void Gauss::print_mat(){
    mat.print();
}

void Gauss::print_b(){
    b.print();
}
