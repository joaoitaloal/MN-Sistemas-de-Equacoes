#ifndef MN_GAUSSJORDAN_H
#define MN_GAUSSJORDAN_H

#include "Gauss.h"

class GaussJordan : public Gauss{
    public:
        using Gauss::Gauss;
        void iterar(int i) override;
};

#endif // MN_GAUSSJORDAN_H