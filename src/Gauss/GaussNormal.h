#ifndef MN_GAUSSNORMAL_H
#define MN_GAUSSNORMAL_H

#include "Gauss.h"

class GaussNormal : public Gauss {
    public:
        using Gauss::Gauss;
        void iterar(int i) override;
};

#endif // MN_GAUSSNORMAL_H