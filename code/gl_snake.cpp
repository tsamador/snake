#ifndef GL_SNAKE_DEF
#define GL_SNAKE_DEF


#include "..\lib\glad\glad.h"           //NOTE(Tanner): Have to include Glad first as it has the openGL include headers
#include "..\lib\GLFW\glfw3.h"
#include "ShaderLoader.h"
#include "stb_image.h"
#include "snake.h"
#include <stdio.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

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
    GLFWwindow* window = glfwCreateWindow(800,600, "Snake", 0,0);

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

    //We only need to use Squares for this Project, single primitive
    float vertices[] =  {
        0.5f, 0.5f, 0.0f,               //top right
        0.5f, -0.5f, 0.0f,              //bottom right
        -0.5f, -0.5f, 0.0f,             //bottom left
        -0.5f, 0.5f, 0.0f               //top left
    };

    unsigned int indices[] = {
        0, 1, 3,        //First Triangle
        1, 2, 3         //Second Triangle
    };


    //set up our vertex buffers
    unsigned int VBO, VAO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    glBindVertexArray(VAO);

    //Create our buffer on the GPU and Send our vertices to it.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,  GL_STATIC_DRAW);

    //Create our buffer on the GPU and send our indices to it.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //Now that we have setup our Vertices, start our main loop.
    while(!glfwWindowShouldClose(window))
    {
        
    }



}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0,width,height);
}


void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window,true);
    }

    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        yOffset += 0.005f;
        shader.setUniFloat("yOffset", yOffset);
    }

    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        
        yOffset -= 0.005f;
        shader.setUniFloat("yOffset", yOffset);
    }

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        xOffset -= 0.005f;
        shader.setUniFloat("xOffset", xOffset);
    }

    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        xOffset += 0.005f;
        shader.setUniFloat("xOffset", xOffset);
    }
}

#endif

