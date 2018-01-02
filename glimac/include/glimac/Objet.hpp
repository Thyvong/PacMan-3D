class Objet
{
public:
	Objet();
	~Objet();

	float x,y,z;//POSITION
	float hauteur,largeur;//DIMENSION en cube

	int orientation;//Enum??


};

class Item : public Objet
{
public:
	Item();
	~Item();

	int point;
	int active;
};

class Mur : public Objet
{
public:
	Mur();
	~Mur();
	
};

class Personnage : public Objet
{
public:
	Personnage();
	~Personnage();

	virtual void seDeplacer();
};

class Imacman : public Personnage
{
public:
	Imacman();
	~Imacman();

	void seDeplacer();
};

class Fantome : public Personnage
{
public:
	Fantome();
	~Fantome();

	void seDeplacer();
};
