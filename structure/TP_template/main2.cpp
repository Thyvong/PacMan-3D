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
    std::cout<<"YES"<<std::endl;
    Camera camera(10,0,0);
    Terrain jeu;
    glm::mat4 view;

    PacMan& pacman=jeu.getPacman();
    

    Mur& monMur=jeu.getMur();
    std::vector<glm::vec3> maze=jeu.getMaze();
    
    std::cout<<"YES"<<std::endl;
    
    // Application loop:
    bool done = false;
    bool down=false;

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

                        case SDLK_DOWN:{

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
        pacman.update();
        view=camera.gettrackviewmat(pacman);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(pacman.getApparence()->vao);
        
        
        //ca marche aussi
        glUniformMatrix4fv(MVMat_loc,1,GL_FALSE,glm::value_ptr(view*pacman.getMod()));
        glUniformMatrix4fv(NormalMat_loc,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(view*pacman.getMod()))));
        glUniformMatrix4fv(MVPMat_loc,1,GL_FALSE,glm::value_ptr(pacman.getProjection()*view*pacman.getMod()));


        if(pacman.getApparence()->type==Boule){
            glDrawArrays(GL_TRIANGLES, 0, pacman.getApparence()->nbpoint);
        }
        

        glBindVertexArray(0);

        //DESSIN DE MAZE

        for (int i = 0; i < maze.size(); ++i)
        {
        glBindVertexArray(monMur.getApparence()->vao);
        monMur.setCoordonnee(maze[i]);
        
        //TEST
        glUniformMatrix4fv(MVMat_loc,1,GL_FALSE,glm::value_ptr(view*monMur.getMod()));
        glUniformMatrix4fv(NormalMat_loc,1,GL_FALSE,glm::value_ptr(glm::transpose(glm::inverse(view*monMur.getMod()))));
        glUniformMatrix4fv(MVPMat_loc,1,GL_FALSE,glm::value_ptr(monMur.getProjection()*view*monMur.getMod()));
        
        if (monMur.getApparence()->type==Boite){

            glDrawElements(GL_TRIANGLES,monMur.getApparence()->nbpoint,GL_UNSIGNED_INT,0);
        }


        }//endfor
        glBindVertexArray(0);
        // Update the display
        windowManager.swapBuffers();
    }


    return EXIT_SUCCESS;
}
