//
// Created by Mathieu on 30/12/2017.
//

#include "../includes/Terrain.h"

Terrain::Terrain() {

}

PacMan & Terrain::getPacman() {
    return m_pacMan;
}

FantomeBleu & Terrain::getFb() {
    return m_fb;
}

FantomeJaune & Terrain::getFj() {
    return m_fj;
}

FantomeRose & Terrain::getFrs() {
    return m_frs;
}

FantomeRouge &Terrain::getfrg() {
    return m_frg;
}

std::vector<Nourriture *> &Terrain::getNourriture() {
    return m_nourriture;
}

std::vector<Coordonnee> & Terrain::getMur() {
    return m_mur;
}
