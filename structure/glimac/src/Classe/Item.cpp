//
// Created by Mathieu on 30/12/2017.
//

#include <fstream>
#include <iostream>
#include <Classe/Item.h>


Item::Item(Modele* modele,glm::vec3 pos){
    type=Entity;
    orientation=0;
    Projection=glm::perspective(glm::radians(70.f),800.0f/600.0f,0.1f,100.f);
    setCoordonnee(pos);
    apparence=modele;

}

void Item::calculModeleMatrix(){//DEPUIS LE CENTRE DE LA MAP
    Mod=glm::rotate(
        glm::translate(glm::mat4(),m_coordonnee),
        glm::radians(orientation*90.f),//picky son of ...
        glm::vec3(0,1,0)
    );
    
}

void Item::update(){
    calculModeleMatrix();
}
Modele* Item::getApparence(){
    return apparence;
}
glm::vec3 Item::getCoordonnee() {
    return m_coordonnee;
}
void setCoordonnee(glm::vec3 coord);

glm::mat4 Item::getProjection(){
    return Projection;
}
glm::mat4 Item::getMod(){
    return Mod;
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
int Item::dessin(){
    return 0;
}
void Item::setCoordonnee(glm::vec3 coord) {

    m_coordonnee = coord;
    calculModeleMatrix();

}

