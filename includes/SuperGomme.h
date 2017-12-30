//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_SUPERGOMME_H
#define IMACMAN_SUPERGOMME_H

#include "Gomme.h"

class SuperGomme : public Gomme {

    public:
        SuperGomme();
        int Bonus() override;
};
#endif //IMACMAN_SUPERGOMME_H
