#ifndef DEF_SNAKE_H
#define DEF_SNAKE_H

//NOTE(Tanner): I don't like including these here but will do for now
#include "..\lib\glad\glad.h"           //NOTE(Tanner): Have to include Glad first as it has the openGL include headers
#include "..\lib\GLFW\glfw3.h"
#include "gl_snake.h"
#include "snake_game_state.h"
#include "ShaderLoader.h"
#include "SnakeEntity.h"
#include "FoodEntity.h"


void SnakeMainLoop(GLFWwindow* window);
snake_game_state* InitGameState( GLFWwindow* window);
void UpdateEntities(snake_game_state* gameState);
SnakeEntity* CreateSnake();
FoodEntity* CreateFood();


#endif