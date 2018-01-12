//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_TERRAIN_H
#define IMACMAN_TERRAIN_H

#include <vector>
#include <fstream>
#include <string>

#include "PacMan.h"
#include "Fantome.h"
#include "Nourriture.h"
#include "Mur.hpp"
#include "Item.h"
#include "Personnage.h"


void tilemapPosition(glm::vec3 pos,int rows,int cols,int& indice1,int& indice2);


class Terrain{

    private:

        PacMan*  m_pacMan;
        FantomeBleu*   m_fb;
        FantomeJaune*   m_fj;
        FantomeRose*  m_frs;
        FantomeRouge*  m_frg;

        std::vector<Nourriture*> m_nourriture;
        std::vector<Mur*> m_maze;

        Modele* rouge,*rose,*bleu,*jaune,*mur,*pac,*gomme,*sgomme,*fruit,*vide;
        std::unique_ptr<Image> rougetex,bleutex,jaunetex,rosetex,murtex,pactex,gommetex,fruittex;

        

        

    public:

        Terrain(std::string nom);
        ~Terrain();
        int m_rows,m_cols;


        static std::vector<std::vector<Item*>> m_tilemap;// n'est pas updaté par les déplacements
        static int supermodecpt;// décompte

        PacMan* getPacman();
        FantomeBleu* getFb();
        FantomeJaune* getFj();
        FantomeRose* getFrs();
        FantomeRouge* getFrg();
        
        // on l'utilisera surtout pour pacman
        void collision(PacMan* perso,Nourriture* food);
        void collision(PacMan* perso1,Fantome* perso2);
        void LookAfterPacman();
        void startSuper();
        bool isSuper();
        void Supercountdown();


        std::vector<Nourriture*> getNourriture();
        std::vector<Mur*> getMaze();

        void load(std::string nom);
        int dessin(glm::mat4 view);
        void afterPacDeath();
        int gameover();


};

#endif //IMACMAN_TERRAIN_H
