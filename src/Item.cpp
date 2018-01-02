//
// Created by Mathieu on 30/12/2017.
//

#include <fstream>
#include <iostream>
#include "../includes/Item.h"


Item::Item(){}


int & Item::getId() {
    return m_id;
}

Coordonnee & Item::getCoordonnee() {
    return m_coordonnee;
}

int Item::wFile() {
    /*std::ofstream fichier("test.txt", std::ios::out);  //déclaration du flux et ouverture du fichier
    if(fichier)  // si l'ouverture a réussi
    {
        // instructions
        fichier << getId() ;
        //std::cout << m_id;
    }
    else  // sinon
        std::cerr << " Erreur à l'ouverture ! " << std::endl;*/
}

void Item::setCoordonnee(int x, int y, int z) {

    m_coordonnee = Coordonnee(x,y,z);

}

