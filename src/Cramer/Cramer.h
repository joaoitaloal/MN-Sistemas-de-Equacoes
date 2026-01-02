#ifndef MN_CRAMER_H
#define MN_CRAMER_H

#include "Gauss/GaussJordan.h"
#include <string>

class Cramer {
    public:
        Cramer(Matrix m, Matrix b, double a);
        
        vector<double> deslocamento_normal();
        vector<double> amplitude_normal();

        vector<double> deslocamento_jordan();
        vector<double> amplitude_jordan();

    protected:
        Matrix m;
        Matrix b;
        double a;

        vector<double> aux(Matrix& b); //recebe a matriz b (dos termos independentes) e transforma em um vetor
        double calc_det(Matrix& m, bool usar_jordan);
        vector<double> calc_desloc(bool usar_jordan);
        vector<double> calc_amplitude(bool usar_jordan);
        vector<double> b_vetor;

};

#endif