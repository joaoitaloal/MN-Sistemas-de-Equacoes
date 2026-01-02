#include "Gauss/GaussJordan.h"
#include "Cramer/Cramer.h"

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
           int entrada;
           cin >> entrada;
           C.set(i, 0, entrada);
        }
        cout << "\n";

        Cramer cramer(C, V, a);
        vector<double> deslocamentos = cramer.deslocamento_normal();
        vector<double> amplitudes = cramer.amplitude_normal();
        vector<double> rompimentos;

        for (int i = 0; i < n; i++) {
            if (amplitudes[i] > 3.0) {
                rompimentos.push_back(i);
            }
        }
        
        cout << "-------------------- DESLOCAMENTOS --------------------" << endl << endl;
        cout << "[" << endl << endl;
        for (int i = 0; i < deslocamentos.size(); i++){
            cout << deslocamentos[i] << " ";
        }
        cout << "]" << endl << endl;
        cout << "-------------------- AMPLITUDES --------------------" << endl << endl;
        cout << "[" << endl << endl;
        for (int i = 0; i < amplitudes.size(); i++){
            cout << amplitudes[i] << " ";
        }
        cout << "]" << endl << endl;
        if (rompimentos.size() > 0){
            cout << "Houve rompimentos nas cordas: ";
            for (int i = 0; i < rompimentos.size(); i++){
                cout << rompimentos[i] + 1 << " ";
            }
        } else {
            cout << "Não houve rompimentos nas cordas" << endl;
        }
        cout << endl;

        char c;
        cout << "Você deseja continuar? [S/N]: ";
        cin >> c;
        if (c == 'N') continua = false;
        cout << "\n";

        contador++;
    }
    return 0;
}
