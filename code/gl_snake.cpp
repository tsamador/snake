#ifndef GL_SNAKE_DEF
#define GL_SNAKE_DEF



#include "gl_snake.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

float xOffset = 0.0f;
float yOffset = 0.0f;


int main()
{
    // Initialize and Configure glfw
    // ----------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //glfw window creation
    // ------------------
    GLFWwindow* window = glfwCreateWindow(1200,800, "Snake", 0,0);

    if(!window)
    {
        puts("Failed to create GLFW Window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        puts("Failed to initialize GLAD\n");
        return -1;
    }


    //    
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindVertexArray(0);

    SnakeMainLoop(window);

    glfwTerminate();
    return 0;


}

void RenderEntities(snake_game_state* gameState, tile tileMap[TABLESIZE][TABLESIZE])
{
    //First Clear the Background to black

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    //Now Draw our snake
    SnakeEntity* snake = gameState->snake;

    snake->_shader->use();
    //Bind Vertex Array
    glBindVertexArray(snake->VAO);
    
    snake_node** segments = snake->segments;
    //Set Uniforms
    for(int i = 0; i < snake->length; i++)
    {
        tile foodTile = tileMap[segments[i]->yCoord][segments[i]->xCoord];
        snake->_shader->setUniFloat("xOffset", foodTile.xOffset);
        snake->_shader->setUniFloat("yOffset", foodTile.yOffset);
        //Draw Elements
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
    }

    

    
    //Now Draw our Food item
    
    FoodEntity* food = gameState->food;

    food->_shader->use();

    glBindVertexArray(food->VAO);
    tile foodTile = tileMap[food->yCoord][food->xCoord];
    food->_shader->setUniFloat("xOffset", foodTile.xOffset);
    food->_shader->setUniFloat("yOffset", foodTile.yOffset);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    glfwSwapBuffers(gameState->window);

    glfwPollEvents();

    glFinish();

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0,width,height);

    //TODO(Tanner): Maybe update our table offsets here???
}

//TODO(Tanner): Move this to a separate file
void ProcessInput(snake_game_state* gameState)
{
    
    gameState->inputs = {};
    
    if(glfwGetKey(gameState->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        gameState->active = false;
    }

    if(glfwGetKey(gameState->window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        gameState->snake->SetDirection(UP);
    }

    if(glfwGetKey(gameState->window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        gameState->snake->SetDirection(DOWN);
    }

    if(glfwGetKey(gameState->window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        gameState->snake->SetDirection(LEFT);
    }

    if(glfwGetKey(gameState->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        gameState->snake->SetDirection(RIGHT);
    }
}

int CreateVertexArrayObject(float* vertices, int verticesSize, unsigned int* indices, int indicesSize)
{
    //set up our vertex buffers
    unsigned int VBO, VAO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    glBindVertexArray(VAO);

    //Create our buffer on the GPU and Send our vertices to it.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices,  GL_STATIC_DRAW);

    //Create our buffer on the GPU and send our indices to it.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    return VAO;
}

#endif

