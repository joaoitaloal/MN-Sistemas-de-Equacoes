#ifndef MN_GAUSSNORMAL_H
#define MN_GAUSSNORMAL_H

#include "Gauss.h"

class GaussNormal : public Gauss {
    public:
        void iterar(int i, float x) override;
};

#endif // MN_GAUSSNORMAL_H