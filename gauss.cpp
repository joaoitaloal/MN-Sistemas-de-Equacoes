#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef vector<vector<double>> matrix;
typedef struct dim {
    size_t r;
    size_t c;
} dim;

matrix init_matrix(size_t s) {
    return vector<vector<double>>(s+1, vector<double>(s+1));
}

matrix init_matrix(size_t s, size_t t) {
    return vector<vector<double>>(s+1, vector<double>(t+1));
}

dim matrix_size(matrix &M) {
    return {M.size() - 1, M[0].size() - 1};
}

void print_matrix(matrix &M) {
    auto[r, c] = matrix_size(M);
    cout << fixed << setprecision(3);
    for (size_t i = 1; i <= r; i++) {
        cout << "[";
        for (size_t j = 1; j <= c; j++) {
            cout << setw(8) << M[i][j] << " "[j == c];
        }
        cout << setw(8) << "]" << endl;
    }
}

void switch_row(matrix &M, size_t x, size_t y) {
    size_t c = matrix_size(M).c;
    matrix aux = init_matrix(1, c);
    for (size_t i = 1; i <= c; i++) {
        aux[1][i] = M[x][i];
        M[x][i] = M[y][i];
        M[y][i] = aux[1][i];
    }
}

// A é a matriz dos coeficientes e B, a dos termos independentes.
// Assume-se que A é quadrada e B é vetor-coluna.
void gauss(matrix &A, matrix &B) {
    size_t s = matrix_size(A).r;
    size_t imax;
    double m;
    for (size_t i = 1; i < s; i++) {
        // Pivoteamento
        imax = i;
        for (size_t j = i+1; j <= s; j++) {
            if (abs(A[j][i]) > abs(A[imax][i])) imax = j;
        }
        switch_row(A, i, imax);
        switch_row(B, i, imax);

        if (A[i][i] == 0) continue;

        // Eliminação de Gauss
        // Obs: Talvez seja melhor definir uma função para somar linhas
        for (size_t j = i+1; j <= s; j++) {
            m = A[j][i] / A[i][i];
            for (size_t k = i; k <= s; k++) {
                A[j][k] -= (A[i][k] * m);
            }
            B[j][1] -= (B[i][1] * m);
        }
    }
}

void gauss_jordan(matrix &A, matrix &B) {
    size_t s = matrix_size(A).r;
    size_t imax;
    double m;
    gauss(A, B);
    for (size_t i = s; i > 1; i--) {
        if (A[i][i] == 0) continue;

        // Eliminação dos valores na parte superior da matriz
        for (size_t j = 1; j < i; j++) {
            m = A[j][i] / A[i][i];
            for (size_t k = j; k <= i; k++) {
                A[j][k] -= (A[i][k] * m);
            }
            B[j][1] -= (B[i][1] * m);
        }
    }
    // Transformação da matriz diagonal em matriz identidade
    for (int i = 1; i <= s; i++) {
        if (A[i][i] != 0) {
            B[i][1] /= A[i][i];
            A[i][i] = 1;
        }
    }
}

int main() {
    double aux_A[5][5] = {
        {0,  0,  0,  0,  0},
        {0,  2,  1,  1,  0},
        {0,  4,  3,  3,  1},
        {0,  8,  7,  9,  5},
        {0,  6,  7,  9,  8}
    };
    double aux_B[5][2] = {
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5}
    };
    size_t s = 4;
    matrix A = init_matrix(s);
    matrix B = init_matrix(s, 1);
    for (size_t i = 1; i <= s; i++) {
        for (size_t j = 1; j <= s; j++) {
            A[i][j] = aux_A[i][j];
        }
    }
    for (size_t i = 1; i <= s; i++) {
        B[i][1] = aux_B[i][1];
    }
    cout << "A:" << endl;
    print_matrix(A);
    cout << endl;
    cout << "B:" << endl;
    print_matrix(B);
    cout << endl;
    gauss(A, B);
    cout << "A:" << endl;
    print_matrix(A);
    cout << endl;
    cout << "B:" << endl;
    print_matrix(B);
    cout << endl;
    gauss_jordan(A, B);
    cout << "A:" << endl;
    print_matrix(A);
    cout << endl;
    cout << "B:" << endl;
    print_matrix(B);
    return 0;
}
