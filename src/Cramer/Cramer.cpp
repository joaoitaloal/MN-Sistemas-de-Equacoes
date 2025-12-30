#include "Cramer.h"

Cramer::Cramer(Matrix m, Matrix b, double a)
: m(m), b(b), a(a), b_vetor(aux(b)){}


vector<double> Cramer::aux(Matrix& b){ //recebe a matriz b (dos termos independentes) e transforma em um vetor
    vector<double> ret;
    for(int i = 0; i < b.get_size().first; i++){
        ret.push_back(b.at(i, 0));
    }
    return ret;
}

vector<double> Cramer::deslocamento_normal(){
    int n = m.get_size().first;
    vector<double> di(n);

    Gauss gn(m, b);
    double det = gn.eliminar_gauss();

    for(int i = 0 ; i < n ; i++){
        Matrix m_aux = m; //para nao alterar na matriz original
        m_aux.change_col(i, b_vetor);
        Gauss gn_aux(m_aux, b);
        di[i] = gn_aux.eliminar_gauss() / det;
    }

    return di;
}

vector<double> Cramer::amplitude_normal(){
    vector<double> di = deslocamento_normal();
    int n = di.size();
    vector<double> amp(n);

    for(size_t i = 0 ; i < di.size() ; i++){
        amp[i] = a*di[i];
    }
    
    return amp;
}

vector<double> Cramer::deslocamento_jordan(){
    int n = m.get_size().first;
    vector<double> di(n);

    GaussJordan gj(m, b);
    double det = gj.eliminar_gauss();

    for(int i = 0 ; i < n ; i++){
        Matrix m_aux = m; //para nao alterar na matriz original
        m_aux.change_col(i, b_vetor);
        GaussJordan gj_aux(m_aux, b);
        di[i] = gj_aux.eliminar_gauss() / det;
    }

    return di;
}

vector<double> Cramer::amplitude_jordan(){
    vector<double> di = deslocamento_jordan();
    int n = di.size();
    vector<double> amp(n);

    for(size_t i = 0 ; i < di.size() ; i++){
        amp[i] = a*di[i];
    }
    
    return amp;
}