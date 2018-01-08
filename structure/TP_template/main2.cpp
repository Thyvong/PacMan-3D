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
    GLint MVPMat_loc=glGetUniformLocation(program.getGLId(),"uMVPMatrix");
    GLint MVMat_loc=glGetUniformLocation(program.getGLId(),"uMVMatrix");
    GLint NormalMat_loc=glGetUniformLocation(program.getGLId(),"uNormalMatrix");

    Camera camera(20,50,0);// angle en degré
    std::string level="level1.txt";
    Terrain jeu(level);
    glm::mat4 view;

    PacMan* pacman=jeu.getPacman();
    

    std::vector<Mur*> maze=jeu.getMaze();
    std::vector<Nourriture*> bouffe=jeu.getNourriture();
    
    // std::cout<<"comparaison glm"<<std::endl<<glm::all(glm::equal(glm::vec3(1,1,0),glm::vec3(1,1,1)))<<std::endl;
    // std::vector<std::vector<int>> test(10,std::vector<int>(20));
    // std::cout<<"taille d'un 2-dim :  "<<test.size()<<std::endl;
    // std::cout<<"taille d'un 2-dim :  "<<test[0].size()<<std::endl;
    // Application loop:
    bool done = false;
    bool down=false;
    std::cout<<"PLOP"<<std::endl;

    std::cout<<"test access pacman"<<std::endl;
    std::cout<<"coord: "<<pacman->getCoordonnee()<<std::endl;
    std::cout<<"tes fini"<<std::endl;

    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            switch(e.type){
                case SDL_QUIT:{
                    done = true; // Leave the loop after this iteration
                }break;

                case SDL_KEYDOWN:{
                    switch(e.key.keysym.sym){
                        case SDLK_ESCAPE:{
                            done=true;
                        }break;
                        case SDLK_UP:{

                        }break;

                        case SDLK_z:{//direction z négatif
                            pacman->deplacement(2);
                            //pacman.deplacement();
                        }break;

                        case SDLK_DOWN:{

                        }break;

                        case SDLK_q:{
                            pacman->deplacement(1);
                        }break;

                        case SDLK_s:{
                            pacman->deplacement(0);
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


        pacman->update();
        view=camera.gettrackviewmat(*pacman);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        glBindVertexArray(pacman->getApparence()->vao);
        //ca marche aussi
        glUniformMatrix4fv(MVMat_loc,1,GL_FALSE,glm::value_ptr(view*pacman->getMod()));
        glUniformMatrix4fv(NormalMat_loc,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(view*pacman->getMod()))));
        glUniformMatrix4fv(MVPMat_loc,1,GL_FALSE,glm::value_ptr(pacman->getProjection()*view*pacman->getMod()));
        if(pacman->getApparence()->type==Boule){
            glDrawArrays(GL_TRIANGLES, 0, pacman->getApparence()->nbpoint);
        }
        glBindVertexArray(0);



        //DESSIN DE MAZE
        for (int i = 0; i < maze.size(); ++i)
        {
            glBindVertexArray(maze[i]->getApparence()->vao);
            //TEST
            glUniformMatrix4fv(MVMat_loc,1,GL_FALSE,glm::value_ptr(view*maze[i]->getMod()));
            glUniformMatrix4fv(NormalMat_loc,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(view*maze[i]->getMod()))));
            glUniformMatrix4fv(MVPMat_loc,1,GL_FALSE,glm::value_ptr(maze[i]->getProjection()*view*maze[i]->getMod()));
            if (maze[i]->getApparence()->type==Boite){
    
                glDrawElements(GL_TRIANGLES,maze[i]->getApparence()->nbpoint,GL_UNSIGNED_INT,0);
            }
            glBindVertexArray(0);
        }//endfor
        


        //DESSIN DE BOUFFE
        for (int i = 0; i < bouffe.size(); ++i)
        {
            glBindVertexArray(bouffe[i]->getApparence()->vao);
            //TEST
            glUniformMatrix4fv(MVMat_loc,1,GL_FALSE,glm::value_ptr(view*bouffe[i]->getMod()));
            glUniformMatrix4fv(NormalMat_loc,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(view*bouffe[i]->getMod()))));
            glUniformMatrix4fv(MVPMat_loc,1,GL_FALSE,glm::value_ptr(bouffe[i]->getProjection()*view*bouffe[i]->getMod()));
            if (bouffe[i]->getApparence()->type==PetiteBoule){
    
                glDrawArrays(GL_TRIANGLES,0,bouffe[i]->getApparence()->nbpoint);
            }
            glBindVertexArray(0);
        }//endfor
        


        // Update the display
        windowManager.swapBuffers();
    }


    return EXIT_SUCCESS;
}

/*
main
    initialize window
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
    initialize shader/matrice
    initialize Terrain, load files
    confirmation dialogue
    countdown
    while(done)
        display
        input
        apply
*/