#include "snake.h"
#include <Windows.h>
#include <time.h>



ShaderLoader shader;
const long int msPerFrame = 100; //Shooting for 10 frames a second
tile tileMap[TABLESIZE][TABLESIZE];
//Our main Game loop
// TODO(Tanner): I don't really like passing in the GL window here,
// May want to eventually change that
void SnakeMainLoop(GLFWwindow* window)
{
    //Initialize our gameState;
    snake_game_state* gameState = InitGameState(window);
    //TODO(Tanner): Enforce 10 frames per second
    while(gameState->active)
    {
        //Process Input
        ProcessInput(gameState);

        //Update Entities
        UpdateEntities(gameState);

        //Render
        //TODO(Tanner): Enforce a framerate
        RenderEntities(gameState, tileMap);
        Sleep(50);
    }

}

snake_game_state* InitGameState(GLFWwindow* window)
{

    shader.Init("..\\code\\shader.vs", "..\\code\\shader.fs");

    snake_game_state*  gameState = (snake_game_state*) malloc(sizeof(snake_game_state));
    gameState->active = true;
    
    gameState->window = window;
    //Clear inputs
    gameState->inputs = {};

    //Setup our tilemap
    //I have coordinates from -0.95 to 0.95
    // 1.9/15 = 0.125 x

    float startingxOffset = -0.9f;
    float startingyOffset = 0.9f;
    for(int row = 0; row < TABLESIZE; row++)
    {
        startingxOffset = -0.9f;
        for(int col = 0; col < TABLESIZE; col++)
        {
            tileMap[row][col].xOffset = startingxOffset;
            tileMap[row][col].yOffset = startingyOffset;
            startingxOffset += 0.095f;
        }
        startingyOffset -= 0.095f;
    }

    gameState->snake = CreateSnake(); 


    gameState->food = CreateFood();

    return gameState;
}

void UpdateEntities(snake_game_state* gameState)
{
    //Update our snake entity   
    gameState->snake->Update();

    bool result = gameState->snake->CheckCollision(gameState->food);
    
    gameState->food->Update(result);
}

 
SnakeEntity* CreateSnake()
{
    //for this project we just have a default shader.
    SnakeEntity* snake = new SnakeEntity();

    // Snake is just a list of red squares
    float size = 0.0425f;
    float vertices[] =  {
        //Vertices              //Color - All green
        size, size, 0.0f,       0.0f, 1.0f, 0.0f,        //top right
        size, -size, 0.0f,      0.0f, 1.0f, 0.0f,        //bottom right
        -size, -size, 0.0f,     0.0f, 1.0f, 0.0f,        //bottom left
        -size, size, 0.0f,      0.0f, 1.0f, 0.0f         //top left
    };

    int verticesSize = sizeof(vertices);
    //Indices for our square
    unsigned int indices[] = {
        0, 1, 3,        //First Triangle
        1, 2, 3         //Second Triangle
    };

    int indicesSize = sizeof(indices);

    snake->VAO = CreateVertexArrayObject(vertices, verticesSize, indices, indicesSize);
    snake->_shader = &shader;

    return snake;
}


FoodEntity* CreateFood()
{
    //For this project we just ahve a default shader.
    FoodEntity* food = new FoodEntity();
    float size = 0.0425f;
    float vertices[] =  {
        //Vertices              //Color - All red
        size, size, 0.0f,       1.0f, 0.0f, 0.0f,        //top right
        size, -size, 0.0f,      1.0f, 0.0f, 0.0f,        //bottom right
        -size, -size, 0.0f,     1.0f, 0.0f, 0.0f,        //bottom left
        -size, size, 0.0f,      1.0f, 0.0f, 0.0f         //top left
    };

    int verticesSize = sizeof(vertices);
    unsigned int indices[] = {
        0, 1, 3,        //First Triangle
        1, 2, 3         //Second Triangle
    };

    int indicesSize = sizeof(indices);

    food->VAO = CreateVertexArrayObject(vertices, verticesSize, indices, indicesSize);
    food->_shader = &shader;

    return food;   
}