//
// Created by Mathieu on 30/12/2017.
//

#include <cstdlib>
#include <Classe/Terrain.h>

std::vector<std::vector<Item*>> Terrain::m_tilemap;
int Terrain::supermodecpt=0;
void tilemapPosition(glm::vec3 pos,int m_rows,int m_cols,int& indice1,int& indice2){
    int i=0,j=0;
    while(i < m_rows)
    {
        if (i*2.0f<=pos.z && pos.z<2.0f*i+2)
        {
            indice1=i;
            while(j<m_cols){
                if (j*2.0f<=pos.x && pos.x<2.0f*j+2)
                {
                    indice2=j;
                    
                }
                j++;
            }
        }
        i++;
    }
}

void Terrain::load(std::string nom){
    std::ifstream flux;
    int getter,n,m,i=0,j=0;
    Mur* addr_mur;
    Gomme* addr_gomme;
    SuperGomme* addr_sgomme;
    Fruit* addr_fruit;

    flux.open(nom.c_str(),std::ios::in);

    if (!flux)
    {  
        std::cout<<"Erreur lors de l'ouverture de: "<<nom<<std::endl;
        return;
    }
    std::cout<<"Ouverture de: "<<nom<<std::endl;
    flux >> n >> m;
    m_rows=n;
    m_cols=m;
    std::vector<Item*> filler(m,nullptr);

        for (i = 0; i < n; i++)
        {
            m_tilemap.push_back(filler);
            for (j = 0; j < m; j++)
            {
                flux >> getter;
                switch(getter){
                    case 0:{ // PAcman
                        m_pacMan = new PacMan(pac,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=m_pacMan;
                    }break;
                    case 1:{ // mur
                        addr_mur=new Mur(mur,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=addr_mur;
                        m_maze.push_back(addr_mur);
                    }break;
                    case 2:{ // gomme
                        addr_gomme=new Gomme(gomme,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=addr_gomme;
                        m_nourriture.push_back(addr_gomme);
                    }break;
                    case 3:{ // sgomme
                        addr_sgomme=new SuperGomme(sgomme,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=addr_sgomme;
                        m_nourriture.push_back(addr_sgomme);
                    }break;
                    case 4:{ // fruit
                        addr_fruit=new Fruit(fruit,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=addr_fruit;
                        m_nourriture.push_back(addr_fruit);
                    }break;
                    case 5:{ // fantome
                        m_fj=new FantomeJaune(jaune,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=m_fj;
                    }break;
                    case 6:{
                        m_frg=new FantomeRouge(rouge,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=m_frg;
                    }break;
                    case 7:{
                        m_frs=new FantomeRose(rose,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=m_frs;
                    }break;
                    case 8:{
                        m_fb=new FantomeBleu(bleu,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                        m_tilemap[i][j]=m_fb;
                    }break;
                    case 9:{ // vide
                        m_tilemap[i][j]=new Item(vide,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                    }break;
                    default:{ // vide
                        m_tilemap[i][j]=new Item(vide,glm::vec3(2.0f*j+1,1,2.0f*i+1));
                    }break;
                }
                std::cout<<getter<<" ";
            }
            std::cout<<std::endl;
        }

        flux.close();


}
Terrain::Terrain(std::string nom) {

    rougetex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/RougeMap.jpg");
    rouge=new Modele(Boule);
    rouge->initialize(rougetex);
    
    bleutex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/BleuMap.jpg");
    bleu=new Modele(Boule);
    bleu->initialize(bleutex);
    
    rosetex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/RoseMap.jpg");
    rose=new Modele(Boule);
    rose->initialize(rosetex);
    
    jaunetex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/JauneMap.jpg");
    jaune=new Modele(Boule);
    jaune->initialize(jaunetex);
    
    murtex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/WallMap.jpg");
    mur=new Modele(Boite);
    mur->initialize(murtex);
    
    pactex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/PacMap.jpg");
    pac=new Modele(Boule);
    pac->initialize(pactex);
    
    gommetex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/GommeMap.jpg");
    gomme=new Modele(PetiteBoule);
    gomme->initialize(gommetex);

    fruittex=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V4/assets/textures/FruitMap.jpg");
    fruit=new Modele(PetiteBoule);
    fruit->initialize(fruittex);

    sgomme=new Modele(PetiteBoule);
    sgomme->initialize(fruittex);

    
    

    vide=new Modele(Empty);

    

    load(nom);
    

}

Terrain::~Terrain(){
    delete rouge;
    delete bleu;
    delete rose;
    delete jaune;
    delete mur;
    delete pac;
    delete gomme;
    delete sgomme;
    delete fruit;

    int i,j;
    for (i = 0; i < m_tilemap.size(); i++)
    {
        for (j = 0; j < m_tilemap[i].size(); j++)
        {
            delete m_tilemap[i][j];
        }
    }

}

PacMan * Terrain::getPacman() {
    return m_pacMan;
}

FantomeBleu * Terrain::getFb() {
    return m_fb;
}

FantomeJaune * Terrain::getFj() {
    return m_fj;
}

FantomeRose * Terrain::getFrs() {
    return m_frs;
}

FantomeRouge *Terrain::getFrg() {
    return m_frg;
}


std::vector<Nourriture *> Terrain::getNourriture() {
    return m_nourriture;
}

std::vector<Mur*> Terrain::getMaze() {
    return m_maze;
}

void Terrain::collision(PacMan* perso,Nourriture* food){
    if(glm::length(
        perso->getCoordonnee()-food->getCoordonnee()) 
        <
        perso->largeur/2+food->largeur/2)
    {
        // la collision a lieu, on demande l'application immédiate des effetsg
        perso->collide(food);
        food->collide();
        
    }
}
void Terrain::collision(PacMan* perso1,Fantome* perso2){
    if(glm::length(
        perso1->getCoordonnee()-perso2->getCoordonnee()) 
        <
        perso1->largeur/2+perso2->largeur/2)
    {
        // la collision a lieu, on demande l'application immédiate des effets
        perso1->collide(perso2);
        perso2->collide(perso1);
        
    }
}
void Terrain::LookAfterPacman(){
    int i,j;
    Etat previous,after;
    tilemapPosition(m_pacMan->getCoordonnee(),m_rows,m_cols,i,j);
    // pour la nourriture, uniquement si sur la meme case pour éviter de manger à distance

    previous=m_pacMan->getetat();
    if(m_tilemap[i][j]->getType()!=IMACMAN){
        //no choice, switch pour caster
        switch(m_tilemap[i][j]->getType()){
            case GUM:{
                collision(m_pacMan,((Gomme*)m_tilemap[i][j]));
            }break;
            case SGUM:{

                collision(m_pacMan,((SuperGomme*)m_tilemap[i][j]));
            }break;
            case FRUIT:{
                collision(m_pacMan,((Fruit*)m_tilemap[i][j]));
            }break;
        }
        

        
    }
    // pour les fantomes
    collision(m_pacMan,m_frg);
    collision(m_pacMan,m_frs);
    collision(m_pacMan,m_fb);
    collision(m_pacMan,m_fj);

    // application des effets selon les états 
    switch(previous){

        case Normal:{
            switch(m_pacMan->getetat()){
                case Death:{
                    // reset
                    afterPacDeath();
                }break;
                case Super:{
                    startSuper();

                }break;
            }
        }break;
    }
    Supercountdown();

}
int Terrain::dessin(glm::mat4 view){
    int i;
    m_pacMan->dessin(view);
    m_fj->dessin(view);
    m_fb->dessin(view);
    m_frs->dessin(view);
    m_frg->dessin(view);
    for (i = 0; i < m_maze.size(); i++)
    {
        m_maze[i]->dessin(view);
    }
    for (i = 0; i < m_nourriture.size(); i++)
    {
        m_nourriture[i]->dessin(view);
    }
    
    
}
void Terrain::startSuper(){
    supermodecpt=4000;
}
bool Terrain::isSuper(){
    if (supermodecpt>0 && m_pacMan->getetat()==Super)
    {  

        return true;
    }
    return false;
}
void Terrain::Supercountdown(){
    if(isSuper()){

        supermodecpt--;
        if(!isSuper()){
            m_pacMan->setetat(Normal);
        }
    }
}
void Terrain::afterPacDeath(){
    m_pacMan->gobacktostart();
    m_pacMan->setetat(Normal);
    m_pacMan->decreaselife();
    supermodecpt=0;

    m_frg->gobacktostart();
    m_frg->setetat(Normal);

    m_frs->gobacktostart();
    m_frs->setetat(Normal);

    m_fb->gobacktostart();
    m_fb->setetat(Normal);

    m_fj->gobacktostart();
    m_fj->setetat(Normal);
}
int Terrain::gameover(){
    if(m_pacMan->life==0){
        return 1;
    }else{
        for (int i = 0; i < m_nourriture.size(); i++)
        {
            if (m_nourriture[i]->isActive())
            {
                return 0;
            }
        }
        return 1;
    }
}