#ifndef MN_GAUSSJORDAN_H
#define MN_GAUSSJORDAN_H

#include "Gauss.h"

class GaussJordan : public Gauss{
    public:
        void iterar(int i, double x) override;
};

#endif // MN_GAUSSJORDAN_H