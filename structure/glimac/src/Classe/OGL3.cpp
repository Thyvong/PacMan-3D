#include "Classe/OGL3.hpp"
#include "Classe/Item.h"

using namespace glimac;

GLint Modele::m_mvloc,Modele::m_mvploc,Modele::m_normalloc;

GLint Modele::getMVloc(){

	return m_mvloc;
}
GLint Modele::getMVPloc(){

	return m_mvploc;
}
GLint Modele::getNormalloc(){

	return m_normalloc;
}
void Modele::setMVloc(GLint val){
	m_mvloc=val;
}
void Modele::setMVPloc(GLint val){
	m_mvploc=val;
}
void Modele::setNormalloc(GLint val){
	m_normalloc=val;
}
void Modele::init_uniformloc(Program* program){
	setMVPloc(glGetUniformLocation(program->getGLId(),"uMVPMatrix"));
	setMVloc(glGetUniformLocation(program->getGLId(),"uMVMatrix"));
	setNormalloc(glGetUniformLocation(program->getGLId(),"uNormalMatrix"));
}


Modele::Modele(Form typedemodele):type(typedemodele){
	
	nbpoint=0;
	
}

void Modele::initialize(){
	glGenBuffers(1,&vbo);
	glGenVertexArrays(1,&vao);
	
	switch(type){
		case Boule:{//no use of ibo grâce à sphere
			Sphere sphere(1,32,16);
			nbpoint=sphere.getVertexCount();

			glBindBuffer(GL_ARRAY_BUFFER,vbo);
			glBufferData(GL_ARRAY_BUFFER, nbpoint* sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER,0);

			glBindVertexArray(vao);
    		glEnableVertexAttribArray(0);
    		glEnableVertexAttribArray(1);
    		glEnableVertexAttribArray(2);
    		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		
    		glVertexAttribPointer(0, 
       			3, GL_FLOAT, GL_FALSE, 
    		    sizeof(ShapeVertex),(const GLvoid*)offsetof(ShapeVertex,position));
    		glVertexAttribPointer(1, 
    		    3, GL_FLOAT, GL_FALSE, 
    		    sizeof(ShapeVertex),(const GLvoid*)offsetof(ShapeVertex,normal));
    		glVertexAttribPointer(2, 
    		    2, GL_FLOAT, GL_FALSE, 
    		    sizeof(ShapeVertex),(const GLvoid*)offsetof(ShapeVertex,texCoords));
		
    		glBindBuffer(GL_ARRAY_BUFFER, 0);
    		glBindVertexArray(0);
			

		}break;
		case PetiteBoule:{//no use of ibo grâce à sphere
			Sphere sphere(0.5f,16,8);
			nbpoint=sphere.getVertexCount();

			glBindBuffer(GL_ARRAY_BUFFER,vbo);
			glBufferData(GL_ARRAY_BUFFER, nbpoint* sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER,0);

			glBindVertexArray(vao);
    		glEnableVertexAttribArray(0);
    		glEnableVertexAttribArray(1);
    		glEnableVertexAttribArray(2);
    		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		
    		glVertexAttribPointer(0, 
       			3, GL_FLOAT, GL_FALSE, 
    		    sizeof(ShapeVertex),(const GLvoid*)offsetof(ShapeVertex,position));
    		glVertexAttribPointer(1, 
    		    3, GL_FLOAT, GL_FALSE, 
    		    sizeof(ShapeVertex),(const GLvoid*)offsetof(ShapeVertex,normal));
    		glVertexAttribPointer(2, 
    		    2, GL_FLOAT, GL_FALSE, 
    		    sizeof(ShapeVertex),(const GLvoid*)offsetof(ShapeVertex,texCoords));
		
    		glBindBuffer(GL_ARRAY_BUFFER, 0);
    		glBindVertexArray(0);
			

		}break;

		//texture à revoir et normal à init
		case Boite:{
			// cubepoint={
			// 	Vertex(glm::vec3(-0.5f,0.5f,0.5f),glm::vec3(-1.0/sqrt(3),1.0/sqrt(3),1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//topleftfront
			// 	Vertex(glm::vec3(0.5f,0.5f,0.5f),glm::vec3(1.0/sqrt(3),1.0/sqrt(3),1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//topright
			// 	Vertex(glm::vec3(0.5f,-0.5f,0.5f),glm::vec3(1.0/sqrt(3),-1.0/sqrt(3),1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//botright
			// 	Vertex(glm::vec3(-0.5f,-0.5f,0.5f),glm::vec3(-1.0/sqrt(3),-1.0/sqrt(3),1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//botleft

			// 	Vertex(glm::vec3(-0.5f,0.5f,-0.5f),glm::vec3(-1.0/sqrt(3),1.0/sqrt(3),-1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//topleftback
			// 	Vertex(glm::vec3(0.5f,0.5f,-0.5f),glm::vec3(1.0/sqrt(3),1.0/sqrt(3),-1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//topright
			// 	Vertex(glm::vec3(0.5f,-0.5f,-0.5f),glm::vec3(1.0/sqrt(3),-1.0/sqrt(3),-1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//botright
			// 	Vertex(glm::vec3(-0.5f,-0.5f,-0.5f),glm::vec3(-1.0/sqrt(3),-1.0/sqrt(3),-1.0/sqrt(3)),glm::vec2(0.5f,0.5f)),//botleft

			// };
			glGenBuffers(1,&ibo);
			cubepoint={
				Vertex(glm::vec3(-1.0f,1.0f,1.0f),glm::vec3(1,0,0),glm::vec2(0.5f,0.5f)),//topleftfront
				Vertex(glm::vec3(1.0f,1.0f,1.0f),glm::vec3(0,1,0),glm::vec2(0.5f,0.5f)),//topright
				Vertex(glm::vec3(1.0f,-1.0f,1.0f),glm::vec3(0,0,1),glm::vec2(0.5f,0.5f)),//botright
				Vertex(glm::vec3(-1.0f,-1.0f,1.0f),glm::vec3(1,1,1),glm::vec2(0.5f,0.5f)),//botleft

				Vertex(glm::vec3(-1.0f,1.0f,-1.0f),glm::vec3(1,0,0),glm::vec2(0.5f,0.5f)),//topleftback
				Vertex(glm::vec3(1.0f,1.0f,-1.0f),glm::vec3(0,1,0),glm::vec2(0.5f,0.5f)),//topright
				Vertex(glm::vec3(1.0f,-1.0f,-1.0f),glm::vec3(0,0,1),glm::vec2(0.5f,0.5f)),//botright
				Vertex(glm::vec3(-1.0f,-1.0f,-1.0f),glm::vec3(1,1,1),glm::vec2(0.5f,0.5f)),//botleft

			};
			indice={
			0,1,3,//front
			1,2,3,
			4,5,7,//back
			5,6,7,
			4,1,0,//top
			5,1,4,
			3,2,7,//bot
			6,7,2,
			1,5,2,//right
			2,5,6,
			4,0,7,//left
			0,3,7
			};
			nbpoint=36;


			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
   			glBufferData(GL_ELEMENT_ARRAY_BUFFER,nbpoint*sizeof(uint32_t),indice.data(),GL_STATIC_DRAW);
   			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

			glBindBuffer(GL_ARRAY_BUFFER,vbo);
			glBufferData(GL_ARRAY_BUFFER, 8* sizeof(Vertex), cubepoint.data(), GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER,0);

			glBindVertexArray(vao);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    		glEnableVertexAttribArray(0);
    		glEnableVertexAttribArray(1);
    		glEnableVertexAttribArray(2);
    		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		
    		glVertexAttribPointer(0, 
       			3, GL_FLOAT, GL_FALSE, 
    		    sizeof(Vertex),(const GLvoid*)offsetof(Vertex,position));
    		glVertexAttribPointer(1, 
    		    3, GL_FLOAT, GL_FALSE, 
    		    sizeof(Vertex),(const GLvoid*)offsetof(Vertex,normal));
    		glVertexAttribPointer(2, 
    		    2, GL_FLOAT, GL_FALSE, 
    		    sizeof(Vertex),(const GLvoid*)offsetof(Vertex,texture));
		
    		glBindBuffer(GL_ARRAY_BUFFER, 0);

    		glBindVertexArray(0);
			
		}break;
		case Empty:{
			nbpoint=0;

		}
		default :{

		}break;
	}

}
Camera::Camera(float a,float b, float c){
	distance=a;
	anglex=b;
	angley=c;
}
void Camera::rotateleft(float degree){
	angley+=degree;
}
void Camera::rotateup(float degree){
	anglex+=degree;
}
void Camera::movefront(float delta){
	distance+=delta;
}
glm::mat4 Camera::gettrackviewmat(Item& track) const{
	return glm::translate(glm::mat4(),glm::vec3(0,0,-distance))
	*glm::rotate(glm::mat4(),glm::radians(anglex),glm::vec3(1,0,0))
	*glm::rotate(glm::mat4(),glm::radians(angley),glm::vec3(0,1,0))
	*glm::translate(glm::mat4(),-track.getCoordonnee())
	;
				
				


				
			
				

}
/*
glm::translate(
				glm::rotate(
					glm::mat4(),glm::radians(anglex),glm::vec3(1,0,0)),
				
glm::vec3(0,0,-distance));
glm::rotate(glm::mat4(),glm::radians(anglex),glm::vec3(1,0,0))*glm::translate(glm::mat4(),glm::vec3(0,0,-distance));

glm::translate(glm::rotate(
				glm::rotate(
					glm::mat4(),glm::radians(angley),glm::vec3(0,1,0)),
				glm::radians(anglex),
				glm::vec3(1,0,0)),
glm::vec3(0,0,-distance));

glm::rotate(
				glm::rotate(
					glm::translate(glm::mat4(),glm::vec3(0,0,-distance)),
					glm::radians(anglex),
					glm::vec3(1,0,0)
				),
				glm::radians(angley),
				glm::vec3(0,1,0)
			);


*/