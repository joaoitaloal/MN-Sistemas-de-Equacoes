#include "matriz.h"

Matrix::Matrix(int s){
    matrix = vector<vector<double>>(s+1, vector<double>(s+1));
    matrix_size = {s, s};
}
Matrix::Matrix(int s, int t){
    matrix = vector<vector<double>>(s+1, vector<double>(t+1));
    matrix_size = {s, t};
}

Matrix::Matrix(std::vector<std::vector<double>> matrix_){
    matrix = matrix_;

    // Assumindo que o vetor recebido é uma matriz, obviamente
    matrix_size = {matrix.size(), matrix.at(0).size()};
}

pair<int, int> Matrix::get_size(){
    return matrix_size;
}

/*void Matriz::switch_col(int x, int y){

}*/

void Matrix::switch_row(int x, int y){
    size_t c = matrix_size.second;

    Matrix aux(1, c);

    for (size_t i = 1; i <= c; i++) {
        aux.set(1, i, at(x, i));
        set(x, i, at(y, i));
        set(y, i, aux.at(1, i));
    }
}

void Matrix::set(int x, int y, double val){
    matrix.at(x).at(y) = val;
}

double Matrix::at(int x, int y){
    return matrix.at(x).at(y);
}

void Matrix::print() {
    cout << fixed << setprecision(PRINT_PRECISION_MATRIX);
    for (size_t i = 1; i <= matrix_size.first; i++) {
        cout << "[";
        for (size_t j = 1; j <= matrix_size.second; j++) {
            cout << setw(PRINT_W_VALUES) << at(i, j) << " "[j == matrix_size.second];
        }
        cout << "  ]" << endl;
    }
}