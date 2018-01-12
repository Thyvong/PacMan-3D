//
// Created by Mathieu on 30/12/2017.
//

#include <iostream>
#include <Classe/Nourriture.h>
#include <Classe/PacMan.h>


int PacMan::mange(Nourriture * nourriture) {

    if(nourriture->isActive()){
        if(nourriture->getType()==SGUM)
        {
            std::cout<<"JE PASSE EN SUPER MODE"<<std::endl;
            setetat(Super);
        }
        return nourriture->Bonus();
    }
    return 0;
}


void PacMan::decreaselife(){
    life--;
}
void PacMan::increaselife(){
    life++;
}


int PacMan::collide(Nourriture* nourriture){

    return mange(nourriture);
}
int PacMan::collide(Fantome* ghost){

    if(ghost->getetat()!=Death){
        if (etat==Super)
        {
            return 1000;
        }else{
            setetat(Death);
            return -1000;
        }
    }
    
}









