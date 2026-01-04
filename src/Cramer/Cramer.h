#ifndef MN_CRAMER_H
#define MN_CRAMER_H

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

        double calc_det(Matrix& m, bool usar_jordan);
        vector<double> calc_desloc(bool usar_jordan);
        vector<double> calc_amplitude(bool usar_jordan);

};

#endif
