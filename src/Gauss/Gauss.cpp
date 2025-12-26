#include <iostream>
#include "Gauss.h"
#include "../Matriz/Matriz.h"

Gauss::Gauss(Matriz m, std::vector<double> b)
: mat(m), b(b) {}

void Gauss::eliminar_gauss(){
    std::pair p = mat.get_size();
    int n = p.first;
    int m = p.second;
    int num_trocas = 0;

    for (int i=0; i < n-1; i++){
        // pivotação
        int maior = i;
        
        for(int j = i + 1; j < n; ++j){
            if (abs(mat.at(i,j)) > abs(mat.at(i, maior))) maior = j;
        }

        if (maior != i){
            num_trocas++;
            mat.switch_row(i, maior);
        }

        for (int k=i+1; k < n; k++){
            float x = -mat.at(k, i)/mat.at(i, i);
            mat.set(k, i, 0);

            // iteracao respectiva
            iterar(i, x);
            b[k] = b[k] + x*b[i];
        }
    }
}*/