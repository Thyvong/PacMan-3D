#ifndef OGL3_H
#define OGL3_H

#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <glimac/common.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include "glimac/Sphere.hpp"
#include <math.h>

class Item;
using namespace glimac;
enum Form{Boule,Boite,Empty,PetiteBoule};

class Vertex{
public:
    Vertex(glm::vec3 a,glm::vec3 b,glm::vec2 c):position(a),normal(b),texture(c){}
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texture;
};


class Modele
{
public:
	Modele(){}
	Modele(Form typedemodele);
	~Modele(){
		glDeleteBuffers(1,&vbo);
		glDeleteBuffers(1,&ibo);
    	glDeleteVertexArrays(1,&vao);
	}


	//vbo/vao et factory shit
	int nbpoint;
	Form type;
	GLuint vbo,vao,ibo;
	//pour les sphere pas besoin de créer un attribut, on ne l'utilisera pas après
	std::vector<Vertex> cubepoint;//pour les cubes
	std::vector<uint32_t> indice;
	

	void initialize();
	
};


class Camera
{
public:
	Camera(){
		distance=5;
		anglex=0;
		angley=0;
	}
	Camera(float a,float b, float c);
	float distance,anglex,angley;


	void rotateleft(float degree);
	void rotateup(float degree);
	void movefront(float delta);

	glm::mat4 gettrackviewmat(Item& track) const;
	//entité différente ou switch mode ?
};
#endif