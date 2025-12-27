#include "GaussNormal.h"
#include "../Matrix/Matrix.h"

void GaussNormal::iterar(int i){
    int n = mat.get_size().first;

    for (int k = i+1; k < n; k++){
        if (k == i) continue;
        double x = -mat.at(k, i)/mat.at(i, i);
        mat.set(k, i, 0);

        for (int j = i + 1; j < n; j++) {
            mat.set(k, j, mat.at(k, j) + (x * mat.at(i, j)));
        }
            
        b.set(k, 0, b.at(k, 0) + x * b.at(i, 0));
    }
}