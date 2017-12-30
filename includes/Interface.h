//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_INTERFACE_H
#define IMACMAN_INTERFACE_H

class Interface{
    private:
        int vies;
        int score;

    public:
        Interface();
        int wFile();//ecriture sur fichier
        int rFile();//lecture sur fichier
        int pause();
        int recommencer();
        int continuer();
        int quitter();


};
#endif //IMACMAN_INTERFACE_H
