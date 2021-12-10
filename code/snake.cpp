#include "SnakeEntity.h"
#include "snake.h"
#include "gl_snake.h"

//Our main Game loop
// TODO(Tanner): I don't really like passing in the GL window here,
// May want to eventually change that
void SnakeMainLoop(GLFWwindow* window)
{
    //Initialize our gameState;
    snake_game_state* gameState;

    InitGameState(gameState, window);

    while(gameState->active)
    {
        //Process Input
        ProcessInput(gameState);

        //Update Entities
        UpdateEntities(gameState);
        //Render
        RenderEntities(gameState);
    }

}

void InitGameState(snake_game_state* gameState, GLFWwindow* window)
{

    gameState = (snake_game_state*) malloc(sizeof(snake_game_state));
    gameState->active = true;
    
    gameState->window = window;
    //Clear inputs
    gameState->inputs = {};
    
}

void UpdateEntities(snake_game_state* gameState)
{

}