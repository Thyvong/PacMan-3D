#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>


#include <Classe/OGL3.hpp>
#include <Classe/Terrain.h>

using namespace glimac;


int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }


    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/"+argv[1],applicationPath.dirPath() + "shaders/"+argv[2]);
    program.use();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    glEnable(GL_DEPTH_TEST);
    //ici initialiser les locations uniformes
    // Modele::init_uniformloc(&program);
    
    
    Modele::setMVPloc(glGetUniformLocation(program.getGLId(),"uMVPMatrix"));
    Modele::setMVloc(glGetUniformLocation(program.getGLId(),"uMVMatrix"));
    Modele::setNormalloc(glGetUniformLocation(program.getGLId(),"uNormalMatrix"));
    Modele::setTextureloc(glGetUniformLocation(program.getGLId(),"uTexture"));

    Camera camera(20,50,0);// angle en degré
    std::string level="level1.txt";
    Terrain jeu(level);
    glm::mat4 view;

    PacMan* pacman=jeu.getPacman();
    FantomeBleu* bleu=jeu.getFb();
    FantomeRouge* rouge=jeu.getFrg();
    FantomeRose* rose=jeu.getFrs();
    FantomeJaune* jaune=jeu.getFj();
    

    std::vector<Mur*> maze=jeu.getMaze();
    std::vector<Nourriture*> bouffe=jeu.getNourriture();
    
    // std::unique_ptr<Image> terremap,lunemap;
    // terremap=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V3/assets/textures/EarthMap.jpg");
    // lunemap=loadImage("/home/ken/Documents/C++/IMACMAN COMMUN/PROJET V3/assets/textures/MoonMap.jpg");
    // if(!terremap||!lunemap){
    //     std::cout<<"Une texture n'a pas été chargé par SDL"<<std::endl;
    // }
    // GLuint terretex,lunetex;
    // glGenTextures(1,&terretex);
    // glGenTextures(1,&lunetex);

    // glBindTexture(GL_TEXTURE_2D,terretex);
    // glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,terremap->getWidth(),terremap->getHeight(),0,GL_RGBA,GL_FLOAT,terremap->getPixels());
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glBindTexture(GL_TEXTURE_2D,0);

    // glBindTexture(GL_TEXTURE_2D,lunetex);
    // glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,lunemap->getWidth(),lunemap->getHeight(),0,GL_RGBA,GL_FLOAT,lunemap->getPixels());
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glBindTexture(GL_TEXTURE_2D,0);


    // GLint uniform_texloc=glGetUniformLocation(program.getGLId(),"uTexture");



    // Application loop:
    bool done = false;
    bool down=false;


    // pour garder la touche enfoncée
    SDL_EnableKeyRepeat(1, 10);
    //activer unicode en cas de probleme de qwerty
    SDL_EnableUNICODE(1);

    while(!done&&!jeu.gameover()) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            switch(e.type){
                case SDL_QUIT:{
                    done = true; // Leave the loop after this iteration
                }break;

                case SDL_KEYDOWN:{
                    // unicode
                    if(e.key.keysym.unicode > 0 || e.key.keysym.unicode < 256){
                        e.key.keysym.sym = (SDLKey) e.key.keysym.unicode;
                    }
                    switch(e.key.keysym.sym){
                        case SDLK_ESCAPE:{
                            done=true;
                        }break;
                        case SDLK_UP:{

                        }break;

                        case SDLK_z:{//direction z négatif
                            pacman->deplacement(0);
                           

                        }break;

                        case SDLK_DOWN:{

                        }break;

                        case SDLK_q:{
                            pacman->deplacement(1);
                        }break;

                        case SDLK_s:{
                            pacman->deplacement(2);
                        }break;
                        case SDLK_d:{
                            pacman->deplacement(3);
                        }break;
                    }
                }break;
                case SDL_MOUSEMOTION:{
                    if(down){
                        
                        camera.rotateleft(e.motion.xrel);
                        camera.rotateup(e.motion.yrel);

                        

                    }
                }break;
                case SDL_MOUSEBUTTONDOWN:{
                    down=true;

                }break;

                case SDL_MOUSEBUTTONUP:{
                    down=false;
                }break;
            }
                
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        // bleu->deplacement();
        // rouge->deplacement();
        // rose->deplacement();
        // jaune->deplacement();

        pacman->update();//appelle simplement calculemodelematrix() qui est privé
        jeu.LookAfterPacman();
        view=camera.gettrackviewmat(*pacman);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // glBindTexture(GL_TEXTURE_2D,lunetex);
        // glUniform1i(uniform_texloc, 0);

        jeu.dessin(view);

        // Update the display
        windowManager.swapBuffers();
    }

    // glDeleteTextures(1,&terretex);
    // glDeleteTextures(1,&lunetex);

    return EXIT_SUCCESS;
}

/*
main
    initialize window
    shader via program
    do
        do
            displaymenu(exit=0)
        while(choice)
        switch(choice)
            level1
            level2
            level3
    while(exit)

level()
    initialize uniform stuff
    initialize Terrain, load files
    confirmation dialogue
    countdown
    while(done)
        input
        apply move pacman
        applymove fantome
        test terrain
            (collision bouffe puis fantome puis effet en conséquences)
            

*/