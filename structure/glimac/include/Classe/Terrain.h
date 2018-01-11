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
    //A priori pas besoin de pointeur mais à voir
        //need pointer of those
        PacMan*  m_pacMan;
        FantomeBleu*   m_fb;
        FantomeJaune*   m_fj;
        FantomeRose*  m_frs;
        FantomeRouge*  m_frg;
        //Mur m_mur;// si on passe en tilemap, il e nfaudra plus qu'un

        //vec2 pour les indice de tilemap
        std::vector<Nourriture*> m_nourriture;
        std::vector<Mur*> m_maze;


        Modele* rouge,*rose,*bleu,*jaune,*mur,*pac,*gomme,*sgomme,*fruit,*vide;

        

        

    public:

        Terrain(std::string nom);
        ~Terrain();
        int m_rows,m_cols;

        // faut il updater la tilemap pour les movements ???
        // --> NE DOIT CONTENIR QUE les infos sur nourriture et murs
        static std::vector<std::vector<Item*>> m_tilemap;// public?
        static int supermodecpt;// decompte

        PacMan* getPacman();
        FantomeBleu* getFb();
        FantomeJaune* getFj();
        FantomeRose* getFrs();
        FantomeRouge* getFrg();
        
        // on l'utilisera surtout pour pacman, il lui renverra tous les scores
        void collision(PacMan* perso,Nourriture* food);
        void collision(PacMan* perso1,Fantome* perso2);
        void LookAfterPacman();
        void startSuper();
        bool isSuper();
        void Supercountdown();

        //renvoie une copie
        std::vector<Nourriture*> getNourriture();
        std::vector<Mur*> getMaze();

        void load(std::string nom);
        int dessin(glm::mat4 view);
        void afterPacDeath();
        int gameover();


};

#endif //IMACMAN_TERRAIN_H
