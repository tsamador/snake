#ifndef DEF_SNAKE_H
#define DEF_SNAKE_H

//NOTE(Tanner): I don't like including these here but will do for now
#include "..\lib\glad\glad.h"           //NOTE(Tanner): Have to include Glad first as it has the openGL include headers
#include "..\lib\GLFW\glfw3.h"
#include "ShaderLoader.h"
#include "SnakeEntity.h"


struct snake_inputs {
    bool up;
    bool down;
    bool left;
    bool right;
};

struct snake_game_state {
    bool active;
    GLFWwindow* window;
    snake_inputs inputs;
    ShaderLoader* shader;
    SnakeEntity* snake;

    //TODO(Tanner): Add entities

};



void SnakeMainLoop(GLFWwindow* window);
snake_game_state* InitGameState( GLFWwindow* window);
void UpdateEntities(snake_game_state* gameState);
SnakeEntity* CreateSnake();







#endif