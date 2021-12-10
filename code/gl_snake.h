#ifndef GL_SNAKE_H_DEF
#define GL_SNAKE_H_DEF

#include "snake.h";

void ProcessInput(snake_game_state* gameState);
void RenderEntities(snake_game_state* gameState);
int CreateVertexArrayObject(float* vertices, int verticesSize, unsigned int* indices, int indicesSize);

#endif