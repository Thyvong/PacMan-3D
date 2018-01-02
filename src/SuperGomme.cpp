//
// Created by Mathieu on 30/12/2017.
//



#include "../includes/Gomme.h"
#include "../includes/SuperGomme.h"

SuperGomme::SuperGomme() {
    m_id = 3;
}

int SuperGomme::Bonus() {
    return Gomme::Bonus();
}


