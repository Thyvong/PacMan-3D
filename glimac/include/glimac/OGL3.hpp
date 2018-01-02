class Window
{
public:
	Window(int a,int b, const char[] c): hauteur(a),largeur(b),titre(c)
	{}
	~Window();

	int hauteur, largeur;
	const char[] titre;
};

class Modele
{
public:
	Modele(int typedemodele):type(typedemodele){}
	~Modele();

	//vbo/vao et factory shit
	int type;
	GLuint vbo,vao,ibo;
	Modele create();
};


class Camera
{
public:
	Camera(arguments);
	~Camera();
	//entité différente ou switch mode ?
};