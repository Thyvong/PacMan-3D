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
    largeur=2;
    hauteur=2;

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
Type Item::getType(){
    return type;
}
glm::vec3 Item::getCoordonnee() {
    return m_coordonnee;
}


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
int Item::dessin(glm::mat4 view){
    GLint mv,mvp,norm;
    mv=Modele::getMVloc();
    mvp=Modele::getMVPloc();
    norm=Modele::getNormalloc();

    glBindVertexArray(apparence->vao);
    //ca marche aussi
    glUniformMatrix4fv(mv,1,GL_FALSE,glm::value_ptr(view*Mod));
    glUniformMatrix4fv(norm,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(view*Mod))));
    glUniformMatrix4fv(mvp,1,GL_FALSE,glm::value_ptr(Projection*view*Mod));
    if(apparence->type==Boule||apparence->type==PetiteBoule){
        glDrawArrays(GL_TRIANGLES, 0, apparence->nbpoint);

    }else{
        glDrawElements(GL_TRIANGLES,apparence->nbpoint,GL_UNSIGNED_INT,0);

    }
    glBindVertexArray(0);
}
void Item::setCoordonnee(glm::vec3 coord) {

    m_coordonnee = coord;
    calculModeleMatrix();

}
