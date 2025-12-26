#include <iostream>
#include "Gauss.h"
#include "../Matriz/matriz.h"

Gauss::Gauss(Matriz m, std::vector<float> b)
: m(m), b(b)) {}

void Gauss::iterar(){
    int n = m.size();
    for (int i=0; i < n-1; i++){
        // pivotação
        int maior = i;
        for(int j = i + 1; j < n; ++j){
            if (abs(m[i][j]) > abs(m[i][maior])) maior = j;
        }

        for (int k=i+1; k < n; k++){
            float x = -m[k][i]/m[i][i];
            m[k][i] = 0;

            // iteracao respectiva
            iterar(i, x);
            b[k] = b[k] + x*b[i];
        }
    }
}