#ifndef GL_SNAKE_H_DEF
#define GL_SNAKE_H_DEF

const int TABLESIZE = 20;

#include "..\lib\glad\glad.h"           //NOTE(Tanner): Have to include Glad first as it has the openGL include headers
#include "..\lib\GLFW\glfw3.h"
#include "ShaderLoader.h"
#include "stb_image.h"
#include "snake_game_state.h"
#include "snake.h"
#include <stdio.h>


void ProcessInput(snake_game_state* gameState);
void RenderEntities(snake_game_state* gameState, tile tileMap[TABLESIZE][TABLESIZE]);
int CreateVertexArrayObject(float* vertices, int verticesSize, unsigned int* indices, int indicesSize);


#endif