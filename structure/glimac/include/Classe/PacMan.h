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
        }
        int mange(Nourriture * nourriture );//valeur retour a voir
        int bonus(Nourriture * nourriture);//valeur retour a voir
        //int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre
        void deplacement(glm::vec3 coordonnee);
        int collision(Item * item); //Valeur de retour à voir (void ou int)

        int croisement(Gomme * gomme);
        int croisement(SuperGomme * supergomme);
        int croisement(Fantome * fantome);
        int croisement(Fruit * fruit);

};
#endif //IMACMAN_PAC_MAN_H
