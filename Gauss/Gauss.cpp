#include <iostream>
#include "Gauss.h"

Gauss::Gauss(std::vector<std::vector<float>> m, std::vector<float> b)
: m(m), b(b), solucao(m.size()) {}

std::vector<float> Gauss::get_solucao(){
    return solucao;
}

void Gauss::iterar(){
    int n = m.size();
    for (int i=0; i < n-1; i++){
        for (int k=i+1; k < n; k++){
            if (m[i][i]!=0){
                float x = -m[k][i]/m[i][i];
                m[k][i] = 0;
                for (int j=i+1; j < n; j++){
                    m[k][j] = m[k][j] + x*m[i][j];
                }
                b[k] = b[k] + x*b[i];
            } else {
                return;
            }
        }
    }
}