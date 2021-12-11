#ifndef GL_SNAKE_GAME_STATE_H
#define GL_SNAKE_GAME_STATE_H

#include "..\lib\glad\glad.h"           //NOTE(Tanner): Have to include Glad first as it has the openGL include headers
#include "..\lib\GLFW\glfw3.h"
#include "ShaderLoader.h"
#include "SnakeEntity.h"
#include "FoodEntity.h"




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
    FoodEntity* food;

};

#endif
