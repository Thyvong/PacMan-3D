//
// Created by Mathieu on 30/12/2017.
//

#include <Classe/Personnage.h>
#include <Classe/Item.h>
#include <Classe/Terrain.h>
/*int Personnage::getVitesse() {
    return vitesse;
}*/

float Personnage::getVitesse() {
    return m_vitesse;
}
void Personnage::gobacktostart(){
	setCoordonnee(origin);
}

void Personnage::deplacement(int orient) {
	glm::vec3 move;
	switch(orient){
		case 0:{
			move=glm::vec3(0,0,1.0f*m_vitesse);
		}break;
		case 1:{
			move=glm::vec3(-1.0f*m_vitesse,0,0);
		}break;
		case 2:{
			move=glm::vec3(0,0,-1.0f*m_vitesse);
		}break;
		case 3:{
			move=glm::vec3(1.0f*m_vitesse,0,0);
		}break;
		default:{
			std::cout<<"Deplacement chelou"<<std::endl;
		}break;
	}
	if(wallcollide(orient,move)){ // true si movement legit
		setCoordonnee(m_coordonnee+move);
		orientation=orient;
	}

    

    /*
	rotation permise ?
		sur les coté
			oui :
				suis je au centre
					oui : return ok, proceed
					non : return denied, end deplacement
			non :
				return ok, proceed
	
	#passé ces test on est sûr
	#que si il se tourne sur les cotés sans être au centre, NOP
	
	coord theorique basé sur orient et vitesse : quel bloc doit t'on regarder
		meme block
			oui :
				direction vers un mur?
					oui :
						deplacement ne dépassant pas le centre
							oui :
								return ok
							non :
								return bouger au  centre

					non :
						allow

			non :
	}
    */
   

}
 
// le bloc i;j a pour coordonnée 2*j+1;1;2*i+1
bool Personnage::wallcollide(int orient,glm::vec3 theoricalmovement){

    int currentid1,currentid2, // your location
    nextid1,nextid2, // the neighboor location in the going-to direction: orient
    theoryid1,theoryid2; // your next location after theorical movement in orient direction

    bool depasse=false;

    // std::cout<<"dim de Tilemap: "<<std::endl
    // <<"n: "<<Terrain::m_tilemap.size()<<std::endl
    // <<"m: "<<Terrain::m_tilemap[0].size()<<std::endl;

	tilemapPosition(m_coordonnee,Terrain::m_tilemap.size(),Terrain::m_tilemap[0].size(),currentid1,currentid2);
	tilemapPosition(m_coordonnee+theoricalmovement,Terrain::m_tilemap.size(),Terrain::m_tilemap[0].size(),theoryid1,theoryid2);
	//std::cout<<"Tilemap trouvé"<<std::endl;
	switch(orient){
		case 0:{
			if(currentid1+1==Terrain::m_tilemap.size()){ // cas "tuyau Mario Sud"
				nextid1=0;
				nextid2=currentid2;	
			}else{
				nextid1=currentid1+1;
				nextid2=currentid2;
			}
			
			if((m_coordonnee+theoricalmovement).z > 2.0f*currentid1+1){
				depasse=true;
			}
		}break;

		case 1:{
			if(currentid2==0){ // cas "tuyau Mario Ouest"
				nextid1=currentid1;
				nextid2=Terrain::m_tilemap[0].size()-1;	
			}else{
				nextid1=currentid1;
				nextid2=currentid2-1;
			}

			if((m_coordonnee+theoricalmovement).x < 2.0f*currentid2+1){
				depasse=true;
			}
		}break;

		case 2:{
			if(currentid1==0){ // cas "tuyau Mario Nord"
				nextid1=Terrain::m_tilemap.size()-1;
				nextid2=currentid2;	
			}else{
				nextid1=currentid1-1;
				nextid2=currentid2;
			}

			if((m_coordonnee+theoricalmovement).z < 2.0f*currentid1+1){
				depasse=true;
			}
		}break;

		case 3:{
			if(currentid2+1==Terrain::m_tilemap[0].size()){ // cas "tuyau Mario Est"
				nextid1=currentid1;
				nextid2=0;	
			}else{
				nextid1=currentid1;
				nextid2=currentid2+1;
			}


			if((m_coordonnee+theoricalmovement).x > 2.0f*currentid2+1){
				depasse=true;
			}
		}break;
		default:{
			std::cout<<"Deplacement dans une direction chelou: "<<orient<<std::endl;
			return false;
		}
	}

	
	
	if(orient!=orientation && orient!= (orientation+2)%4){ // si on souhaite se déplacer " à droite/ à gauche "
		if(Terrain::m_tilemap[nextid1][nextid2]->getType()!=Wall){ // si le bloc adjacent n'est pas un Mur
			//	recentre
			setCoordonnee(glm::vec3(2.0f*currentid2+1,1,2.0f*currentid1+1));
			return true;

		}else{
			std::cout<<"Virage impossible:"<<std::endl
			<<"vous: "<<m_coordonnee<<std::endl
			<<"votre bloc: "<<glm::vec3(2.0f*currentid2+1,1,2.0f*currentid1+1)<<std::endl
			<<"votre bloc dans le tilemap: "<<currentid1<<";"<<currentid2<<std::endl
			<<"le mur: "<<glm::vec3(2.0f*nextid2+1,1,2.0f*nextid1+1)<<std::endl
			<<"votre movement: "<<theoricalmovement<<std::endl;
			return false;
		}
	}


	if(Terrain::m_tilemap[nextid1][nextid2]->getType()==Wall){ // si le bloc adjacent est Mur
		// lookout for wall
		if(Terrain::m_tilemap[theoryid1][theoryid2]->getType()==Wall){
			// mon move me propulse dans le bloc, donc je me reset au centre
			std::cout<<"Movement impossible, Vous foncez DANS le mur:"<<std::endl
			<<"vous: "<<m_coordonnee<<std::endl
			<<"le mur: "<<glm::vec3(2.0f*nextid2+1,1,2.0f*nextid1+1)<<std::endl
			<<"le bloc de destination: "<<glm::vec3(2.0f*theoryid2+1,1,2.0f*theoryid1+1)<<std::endl
			<<"votre movement: "<<theoricalmovement<<std::endl;
			setCoordonnee(glm::vec3(2.0f*currentid2+1,1,2.0f*currentid1+1));
			
			return false;
		}
		if(depasse){
			// mon move me deplace plus loin que le centre, donc je me reset au centre
			std::cout<<"Movement impossible, Vous foncez VERS le mur:"<<std::endl
			<<"vous: "<<m_coordonnee<<std::endl
			<<"le mur: "<<glm::vec3(2.0f*nextid2+1,1,2.0f*nextid1+1)<<std::endl
			<<"le centre du bloc courant: "<<glm::vec3(2.0f*currentid2+1,1,2.0f*currentid1+1)<<std::endl
			<<"votre movement: "<<theoricalmovement<<std::endl;
			setCoordonnee(glm::vec3(2.0f*currentid2+1,1,2.0f*currentid1+1));
			
			return false;
		}
	}

	// move is legit
	return true;
}

void Personnage::changedirection(int orient){
	if(orient >= 0 && orient < 4){
		orientation=orient;
		return;
	}
	orientation=0;
}
Etat Personnage::getetat(){
	return etat;
}
void Personnage::setetat(Etat state){
	etat=state;
}