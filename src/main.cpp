#include "Cramer/Cramer.h"

bool pergunta_continuar() {
    char c = '.';
    bool continua = true;
    while (c != 'S' && c != 's' && c != 'N' && c != 'n') {
        cout << "Voce deseja continuar? [S/N]: ";
        cin >> c;
        if (c == 'N' || c == 'n') continua = false;
        cout << endl;
    }
    return continua;
}

int main(){
    cout << "// ========== Trabalho de Metodos Numericos ========== //" << endl << endl;
    
    bool continua = true;
    int contador = 1;
    while(continua){
        cout << "========== Teste " << contador << " ==========" << endl;
        int n;
        double a;
        cout << "Digite o numero de cordas: ";
        cin >> n;
        cout << "Digite o parametro A: ";
        cin >> a;

        Matrix C(n);
        cout << "Digite os N x N termos da matriz C (C11 ... C1N ... CNN):" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                double entrada;
                cin >> entrada;
                C.set(i, j, entrada);
            }
        }

        Matrix V(n, 1);
        cout << "Digite os N termos do vetor V (V11 ... VN1):" << endl;
        for(int i = 0; i < n; i++){
            double entrada;
            cin >> entrada;
            V.set(i, 0, entrada);
        }
        cout << endl;

        cout << "---------- Valores de Entrada ----------" << endl;
        cout << "Matriz [C]: " << endl;
        C.print();
        cout << endl;

        cout << "Vetor {v}" << endl;
        V.print();
        cout << endl;

        cout << "A = " + to_string(a) << endl << endl; 

        Cramer cramer(C, V, a);
        vector<double> deslocamentos_normal;
        vector<double> deslocamentos_jordan;
        try {
            deslocamentos_normal = cramer.deslocamento_normal();
            deslocamentos_jordan = cramer.deslocamento_jordan();
        } catch (const exception& e){
            cout << e.what() << endl << endl;
            continua = pergunta_continuar();
            contador++;
            continue;
        }
        vector<double> amplitudes_normal = cramer.amplitude_normal();
        vector<double> amplitudes_jordan = cramer.amplitude_jordan();

        vector<double> rompimentos_normal;
        vector<double> rompimentos_jordan;

        for (int i = 0; i < n; i++) {
            if (amplitudes_normal[i] > 3.0) {
                rompimentos_normal.push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (amplitudes_jordan[i] > 3.0) {
                rompimentos_jordan.push_back(i);
            }
        }

        // Resultados

        cout << "// ---------- Resultados ---------- //" << endl << endl;

        // Gauss
        cout << "---------- Gauss normal ----------" << endl;
        cout << "Matriz [C] final de Gauss: " << endl;
        cramer.print_matrix_gauss();
        cout << endl;
        
        cout << "Vetor {v} final de Gauss: " << endl;
        cramer.print_b_gauss();
        cout << endl;
        
        cout << "DESLOCAMENTOS: " << "[ ";
        for (int i = 0; i < deslocamentos_normal.size(); i++){
            cout << deslocamentos_normal[i] << " ";
        }
        cout << "]" << endl;
        cout << endl;

        cout << "AMPLITUDES: ";
        cout << "[ ";
        for (int i = 0; i < amplitudes_normal.size(); i++){
            cout << amplitudes_normal[i] << " ";
        }
        cout << "]" << endl;
        cout << endl;

        cout << "ANALISE: ";
        if (rompimentos_normal.size() > 0){
            cout << "Ha um possivel rompimento nas cordas: ";
            for (int i = 0; i < rompimentos_normal.size(); i++){
                cout << rompimentos_normal[i] + 1 << " ";
            }
        } else {
            cout << "Para o metodo de Gauss normal, todas as cordas estao na margem de seguranca." << endl;
        }
        cout << endl << endl;

        // Jordan
        cout << "---------- Gauss-Jordan ----------" << endl;
        cout << "Matriz [C] final de Jordan: " << endl;
        cramer.print_matrix_jordan();
        cout << endl;
        
        cout << "Vetor {v} final de Jordan: " << endl;
        cramer.print_b_jordan();
        cout << endl;

        cout << "DESLOCAMENTO: " << "[ ";
        for (int i = 0; i < deslocamentos_jordan.size(); i++){
            cout << deslocamentos_jordan[i] << " ";
        }
        cout << "]" << endl;
        cout << endl;

        cout << "AMPLITUDES: ";
        cout << "[ ";
        for (int i = 0; i < amplitudes_jordan.size(); i++){
            cout << amplitudes_jordan[i] << " ";
        }
        cout << "]" << endl;
        cout << endl;

        cout << "ANALISE: ";
        if (rompimentos_jordan.size() > 0){
            cout << "Ha um possivel rompimento nas cordas: ";
            for (int i = 0; i < rompimentos_jordan.size(); i++){
                cout << int(rompimentos_jordan[i] + 1) << " ";
            }
        } else {
            cout << "Para o metodo de Gauss-Jordan, todas as cordas estao na margem de seguranca." << endl;
        }
        cout << endl << endl;

        continua = pergunta_continuar();

        contador++;
    }
    return 0;
}
