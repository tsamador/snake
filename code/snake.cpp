#include "snake.h"


ShaderLoader shader;
//Our main Game loop
// TODO(Tanner): I don't really like passing in the GL window here,
// May want to eventually change that
void SnakeMainLoop(GLFWwindow* window)
{
    //Initialize our gameState;
    snake_game_state* gameState = InitGameState(window);

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

snake_game_state* InitGameState(GLFWwindow* window)
{

    shader.Init("..\\code\\shader.vs", "..\\code\\shader.fs");

    snake_game_state*  gameState = (snake_game_state*) malloc(sizeof(snake_game_state));
    gameState->active = true;
    
    gameState->window = window;
    //Clear inputs
    gameState->inputs = {};



    gameState->snake = CreateSnake(); 


    gameState->food = CreateFood();

    return gameState;
}

void UpdateEntities(snake_game_state* gameState)
{
    //Update our snake entity   
    gameState->snake->Update();

    bool result = gameState->snake->CheckCollision(gameState->food);
    
    gameState->food->update(result);
}


SnakeEntity* CreateSnake()
{
    //for this project we just have a default shader.
    SnakeEntity* snake = new SnakeEntity();

    // Snake is just a list of red squares
    float vertices[] =  {
        //Vertices              //Color - All read
        0.02f, 0.02f, 0.0f,       1.0f, 0.0f, 0.0f,        //top right
        0.02f, -0.02f, 0.0f,      1.0f, 0.0f, 0.0f,        //bottom right
        -0.02f, -0.02f, 0.0f,     1.0f, 0.0f, 0.0f,        //bottom left
        -0.02f, 0.02f, 0.0f,      1.0f, 0.0f, 0.0f         //top left
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

    float vertices[] =  {
        //Vertices              //Color - All white
        0.02f, 0.02f, 0.0f,       1.0f, 1.0f, 1.0f,        //top right
        0.02f, -0.02f, 0.0f,      1.0f, 1.0f, 1.0f,        //bottom right
        -0.02f, -0.02f, 0.0f,     1.0f, 1.0f, 1.0f,        //bottom left
        -0.02f, 0.02f, 0.0f,      1.0f, 1.0f, 1.0f         //top left
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