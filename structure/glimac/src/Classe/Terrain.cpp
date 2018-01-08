//
// Created by Mathieu on 30/12/2017.
//

#include <cstdlib>
#include <Classe/Terrain.h>

std::vector<std::vector<Item*>> Terrain::m_tilemap;

void tilemapPosition(glm::vec3 pos,int m_rows,int m_cols,int& indice1,int& indice2){
    int i=0,j=0;
    std::cout<<"POsition à tester:"<<std::endl
    <<"vous: "<<pos<<std::endl
    <<"m_rows: "<<m_rows<<std::endl
    <<"m_cols: "<<m_cols<<std::endl;
    while(i < m_rows)
    {
        if (i*2.0f<=pos.z && pos.z<2.0f*i+2)
        {
            indice1=i;
            std::cout<<pos.z<<" est compris entre:"<<std::endl
            <<i*2.0f<<" et "<<2.0f*i+1<<std::endl;
            std::cout<<"Found coordinates i"<<std::endl;
            while(j<m_cols){
                if (j*2.0f<=pos.x && pos.x<2.0f*j+2)
                {
                    indice2=j;
                    std::cout<<"Found coordinates j"<<std::endl;
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
    std::cout<<"dim de Tilemap d'après les attributs: "<<std::endl
    <<"n: "<<n<<std::endl
    <<"m: "<<m<<std::endl;
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
    std::cout<<"PLOP"<<std::endl;

}
Terrain::Terrain(std::string nom) {
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
    gomme=new Modele(PetiteBoule);
    gomme->initialize();
    sgomme=new Modele(Boule);
    sgomme->initialize();
    fruit=new Modele(Boule);
    fruit->initialize();
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

FantomeRouge *Terrain::getfrg() {
    return m_frg;
}


std::vector<Nourriture *> Terrain::getNourriture() {
    return m_nourriture;
}

std::vector<Mur*> Terrain::getMaze() {
    return m_maze;
}

