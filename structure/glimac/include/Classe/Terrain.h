//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_TERRAIN_H
#define IMACMAN_TERRAIN_H

#include <vector>
#include "PacMan.h"
#include "Fantome.h"
#include "Nourriture.h"
#include "Mur.hpp"

class Terrain{

    private:
    //A priori pas besoin de pointeur mais à voir
        PacMan  m_pacMan;
        FantomeBleu   m_fb;
        FantomeJaune   m_fj;
        FantomeRose  m_frs;
        FantomeRouge  m_frg;
        Mur m_mur;

        std::vector<Nourriture *> m_nourriture;
        std::vector<glm::vec3> m_maze;
        Modele* rouge,*rose,*bleu,*jaune,*mur,*pac,*gomme,*sgomme,*fruit;
        

    public:
        Terrain();

        PacMan & getPacman();
        FantomeBleu & getFb();
        FantomeJaune & getFj();
        FantomeRose & getFrs();
        FantomeRouge & getfrg();
        Mur& getMur();

        std::vector<Nourriture *> & getNourriture();
        std::vector<glm::vec3> & getMaze();
        

        //Renvoie un nombre aléatoire entre a et b
        int alea(int a, int b);

};
#endif //IMACMAN_TERRAIN_H
