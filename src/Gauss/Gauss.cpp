#include "Gauss.h"

Gauss::Gauss(Matrix m, Matrix b)
: mat(m), b(b) {}

double Gauss::eliminar_gauss(){
    int n = mat.get_size().first;
    int num_trocas = 0;
    double eps = 1e-12;

    for (int i = 0; i < n; i++){
        // pivotação
        int maior = i;
        
        for(int j = i + 1; j < n; ++j){
            if (abs(mat.at(j, i)) > abs(mat.at(maior, i))) maior = j;
        }
        
        if (abs(mat.at(maior, i)) < eps){ //evitar divisao por 0 (ou numeros muito proximos)
            throw runtime_error("Erro: Pivo = 0");
        }

        if (maior != i){
            num_trocas++;
            mat.switch_row(i, maior);
            b.switch_row(i, maior);
        }

        // Antigo iterar
        for (int k = ini_intervalo(i); k < n; k++){
            if(k == i) continue;
            double x = -mat.at(k, i)/mat.at(i, i);
            mat.set(k, i, 0);

            for (int j = i + 1; j < n; j++) {
                mat.set(k, j, mat.at(k, j) + (x * mat.at(i, j)));
            }
                
            b.set(k, 0, b.at(k, 0) + x * b.at(i, 0));
        }
    }
    //tratamento de erro
    int postoA = 0; //quantidade de linhas linearmente independentes
    for (int i = 0; i < n; i++) {
        bool linha_zero = true;
        for (int j = 0; j < n; j++){
            if (abs(mat.at(i,j)) > eps){
                linha_zero = false;
                break;
            }
        }

        if (!linha_zero) postoA++;
        else if (abs(b.at(i,0)) > eps){ //0 + 0 + ... + 0 = (c > 0) -> inconsistente
            throw runtime_error("Erro: Sistema inconsistente");
        }
    }

    if (postoA < n) { //0 + 0 + ... + 0 = 0 -> infinitas solucoes
        throw runtime_error("Erro: Sistema com infinitas solucoes");
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

int Gauss::ini_intervalo(int i){
    return i+1;
}
