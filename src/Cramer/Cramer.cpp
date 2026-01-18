#include "Cramer.h"

Cramer::Cramer(Matrix m, Matrix b, double a)
: m(m), b(b), a(a) {}

double Cramer::calc_det(Matrix& mat, bool usar_jordan){
    //simular o vetor dos termos independentes so com 0 para que
    //so a matriz de coeficientes determine inconsistencias

    if(usar_jordan){
        GaussJordan gj(mat, b);

        double result = gj.eliminar_gauss();

        return result;
    }
    else{
        Gauss gn(mat, b);

        double result = gn.eliminar_gauss();
        
        return result;
    }
}

vector<double> Cramer::calc_desloc(bool usar_jordan){
    int n = m.get_size().first;
    vector<double> di(n, 0);

    double det;
    try {
        if(usar_jordan){
            GaussJordan gj(m, b);

            det = gj.eliminar_gauss();
            jordan_mat = gj.get_mat();
            jordan_b = gj.get_b();
        }
        else{
            Gauss gn(m, b);

            det = gn.eliminar_gauss();
            gauss_mat = gn.get_mat();
            gauss_b = gn.get_b();
        }
    } catch (const exception& e) {
        throw runtime_error(string("Falha ao calcular det(C): ") + e.what());
    }

    if (abs(det) < 1e-12) {
        throw runtime_error("Erro: a determinante é aproximadamente igual a 0");
    }

    for(int i = 0 ; i < n ; i++){
        Matrix m_aux = m; //para nao alterar na matriz original
        m_aux.change_col(i, b);

        double det_i;
        try{
            det_i = calc_det(m_aux, usar_jordan);
            di[i] = det_i / det;
        }
        catch (const exception& e){
            throw runtime_error(string("Falha ao calcular det(C_") + to_string(i+1) + "): " + e.what());
        }
    }
    return di;
}

vector<double> Cramer::deslocamento_normal(){
    return calc_desloc(false);
}

vector<double> Cramer::deslocamento_jordan(){
    return calc_desloc(true);
}

vector<double> Cramer::calc_amplitude(bool usar_jordan){
    vector<double> di = calc_desloc(usar_jordan);
    int n = di.size();
    vector<double> amp(n);
    for(int i = 0 ; i < n ; i++)
        amp[i] = abs(a*di[i]);

    return amp;
}

vector<double> Cramer::amplitude_normal(){
    return calc_amplitude(false);
}

vector<double> Cramer::amplitude_jordan(){
    return calc_amplitude(true);
}

void Cramer::print_matrix_gauss(){
    gauss_mat.print();
}

void Cramer::print_matrix_jordan(){
    jordan_mat.print();
}

void Cramer::print_b_gauss(){
    gauss_b.print();
}

void Cramer::print_b_jordan(){
    jordan_b.print();
}
