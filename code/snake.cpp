#include "SnakeEntity.h";
#include "snake.h";

snake_game_state gameState;
//Our main Game loop
// TODO(Tanner): I don't really like passing int he GL window here,
// May want to eventually change that
void SnakeMainLoop(GLFWwindow* window)
{
    //Initialize our gameState;
    snake_game_state* gameState;

    InitGameState(gameState);
    while(gameState->active)
    {
        //Process Input
        ProcessInput(gameState);


        //Update Entities

        //Render
    }

}

void InitGameState(snake_game_state* gameState)
{
    gameState = (gameState*)malloc(sizeof(gameState));
    gameState->active = true;
    
    //Clear inputs
    gameState->inputs = {};
    

}