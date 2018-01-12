//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_PAC_MAN_H
#define IMACMAN_PAC_MAN_H

#include <Classe/Nourriture.h>
#include <Classe/Personnage.h>
#include <Classe/Fantome.h>


class PacMan : public Personnage{

    public:
        PacMan(){}
        PacMan(Modele* modele,glm::vec3 pos):Personnage(modele,pos){
            type=IMACMAN;
            life=3;
        }
        int life;
        void decreaselife();
        void increaselife();

        int mange(Nourriture * nourriture );

        int collide(Nourriture* nourriture); // applique des effets
        int collide(Fantome* ghost);

        

};
#endif //IMACMAN_PAC_MAN_H
