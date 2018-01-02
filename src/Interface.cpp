//
// Created by Mathieu on 30/12/2017.
//

#include "../includes/Interface.h"
#include "../includes/PacMan.h"
#include "../includes/Gomme.h"
#include "../includes/SuperGomme.h"
#include <fstream>
#include <iostream>

Interface::Interface() {
    m_vies = 3;
    m_score = 0;
}

int Interface::getVies() {
    return m_vies;
}

int Interface::getScore() {
    return m_score;
}

int Interface::wFile() {
    /*SuperGomme gomme = SuperGomme();
    PacMan pacMan = PacMan();
    gomme.wFile();*/
    return 0;
}

int Interface::rFile() {
    return 0;
}

int Interface::pause() {
    return 0;
}

int Interface::recommencer() {
    return 0;
}

int Interface::continuer() {
    return 0;
}

int Interface::quitter() {
    return 0;
}