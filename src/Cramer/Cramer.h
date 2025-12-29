#ifndef MN_CRAMER_H
#define MN_CRAMER_H

#include "../Matrix/Matrix.h"
#include "Gauss/GaussNormal.h"
#include "Gauss/GaussJordan.h"

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
        vector<double> b_vetor;

};

#endif