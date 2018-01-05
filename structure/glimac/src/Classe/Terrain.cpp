//
// Created by Mathieu on 30/12/2017.
//

#include <cstdlib>
#include <Classe/Terrain.h>

Terrain::Terrain() {
    rouge=new Modele(Boule);
    rouge->initialize();
    bleu=new Modele(Boule);
    bleu->initialize();
    rose=new Modele(Boule);
    rose->initialize();
    jaune=new Modele(Boule);
    jaune->initialize();
    mur=new Modele(Boite);
    mur->initialize();
    pac=new Modele(Boule);
    pac->initialize();
    gomme=new Modele(Boule);
    gomme->initialize();
    sgomme=new Modele(Boule);
    sgomme->initialize();
    fruit=new Modele(Boule);
    fruit->initialize();
    

    m_pacMan = PacMan(pac,glm::vec3(0,0,1));
    m_frg = FantomeRouge(rouge,glm::vec3(-1,0,1));
    m_frs = FantomeRose(rose,glm::vec3(-2,0,1));
    m_fj = FantomeJaune(jaune,glm::vec3(-3,0,1));
    m_fb = FantomeBleu(bleu,glm::vec3(-4,0,1));
    m_mur= Mur(mur,glm::vec3(0,0,0));
    
    for (int i = 0; i < 10; i++)
    {
        m_maze.push_back(glm::vec3(2,i*2,1));
    }

}

PacMan & Terrain::getPacman() {
    return m_pacMan;
}

FantomeBleu & Terrain::getFb() {
    return m_fb;
}

FantomeJaune & Terrain::getFj() {
    return m_fj;
}

FantomeRose & Terrain::getFrs() {
    return m_frs;
}

FantomeRouge &Terrain::getfrg() {
    return m_frg;
}

Mur& Terrain::getMur() {
    return m_mur;
}

std::vector<Nourriture *> &Terrain::getNourriture() {
    return m_nourriture;
}

std::vector<glm::vec3>& Terrain::getMaze() {
    return m_maze;
}

