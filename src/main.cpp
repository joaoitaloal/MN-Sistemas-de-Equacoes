#include "Gauss/GaussJordan.h"

int main(){
    bool continua = true;
    int contador = 1;
    while(continua){
        cout << "-------------------- Teste " << contador << " --------------------\n";
        int n;
        double a;
        cout << "Digite o número de cordas e o parametro A (N A): ";
        cin >> n >> a;
        cout << "\n";

        Matrix C(n);
        cout << "Digite os N x N termos da matriz C: (C11... C1N... CNN): ";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                double entrada;
                cin >> entrada;
                C.set(i, j, entrada);
            }
        }
        cout << "\n";

        Matrix V(n, 1);
        cout << "Digite os N termos do vetor V: (V11... VN1): ";
        for(int i = 0; i < n; i++){
            double entrada;
            cin >> entrada;
            C.set(i, 0, entrada);
        }
        cout << "\n";
        // Processamento


        // Saída

        char c;
        cout << "Você deseja continuar? [S/N]: ";
        cin >> c;
        if (c == 'N') continua = false;
        cout << "\n";

        contador++;
    }
    return 0;
}
