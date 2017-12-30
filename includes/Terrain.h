//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_TERRAIN_H
#define IMACMAN_TERRAIN_H

#include <vector>
#include "PacMan.h"
#include "FantomeBleu.h"
#include "FantomeJaune.h"
#include "FantomeRose.h"
#include "FantomeRouge.h"

class Terrain{

    private:
    //A priori pas besoin de pointeur mais à voir
        PacMan  m_pacMan;
        FantomeBleu   m_fb;
        FantomeJaune   m_fj;
        FantomeRose  m_frs;
        FantomeRouge  m_frg;

        std::vector<Nourriture *> m_nourriture;
        std::vector<Coordonnee> m_mur;

    public:
        Terrain();

        PacMan & getPacman();
        FantomeBleu & getFb();
        FantomeJaune & getFj();
        FantomeRose & getFrs();
        FantomeRouge & getfrg();

        std::vector<Nourriture *> & getNourriture();
        std::vector<Coordonnee> & getMur();

};
#endif //IMACMAN_TERRAIN_H
