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

void Item::calculModeleMatrix(){// Depuis le centre de la map
    Mod=glm::rotate(
        glm::translate(glm::mat4(),m_coordonnee),
        glm::radians(orientation*90.f),
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

}
int Item::dessin(glm::mat4 view){
    GLint mv,mvp,norm,tex;
    mv=Modele::getMVloc();
    mvp=Modele::getMVPloc();
    norm=Modele::getNormalloc();
    tex=Modele::getTextureloc();

    glBindVertexArray(apparence->vao);
    glBindTexture(GL_TEXTURE_2D,apparence->texobject);

    glUniformMatrix4fv(mv,1,GL_FALSE,glm::value_ptr(view*Mod));
    glUniformMatrix4fv(norm,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(view*Mod))));
    glUniformMatrix4fv(mvp,1,GL_FALSE,glm::value_ptr(Projection*view*Mod));
    glUniform1i(tex, 0);

    if(apparence->type==Boule||apparence->type==PetiteBoule){
        glDrawArrays(GL_TRIANGLES, 0, apparence->nbpoint);

    }else{
        glDrawElements(GL_TRIANGLES,apparence->nbpoint,GL_UNSIGNED_INT,0);

    }
    glBindTexture(GL_TEXTURE_2D,0);
    glBindVertexArray(0);
}
void Item::setCoordonnee(glm::vec3 coord) {

    m_coordonnee = coord;
    calculModeleMatrix();

}
