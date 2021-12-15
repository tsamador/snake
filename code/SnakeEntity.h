#ifndef DEF_SNAKE_ENTITY_H
#define DEF_SNAKE_ENTITY_H

#include "ShaderLoader.h"
#include "FoodEntity.h"
#include <math.h>

enum Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

struct snake_node {
    float xOffset;
    float yOffset;
    Direction direction;
    snake_node* next;
};


struct SnakeEntity {

   ShaderLoader* _shader;
   snake_node** segments;
   float radius;
   int VAO;
   int length;

   SnakeEntity() {
       segments = (snake_node**)malloc(sizeof(snake_node*)*50);
       segments[0] = (snake_node*)malloc(sizeof(snake_node));
       segments[0]->yOffset = 0.0f;
       segments[0]->xOffset = 0.0f;
       segments[0]->direction = RIGHT;
       radius = 0.02f;
       length = 1;
   }

   void SetDirection(Direction d) 
   {
       segments[0]->direction = d;
   }

   void Update() 
   {
    
       for(int i = length - 1; i >=0; i--)
       {
        switch(segments[i]->direction) 
        {
            case LEFT: 
            {
               if(segments[i]->xOffset > -0.95f) {
                    segments[i]->xOffset -= 0.001f;
                }
            } break;
            case UP: 
            {
                if(segments[i]->yOffset < 0.95f) {
                    segments[i]->yOffset += 0.001f;
                }
            } break;
            case RIGHT: 
            {
                if(segments[i]->xOffset < 0.95f) {
                    segments[i]->xOffset += 0.001f;
                }
            } break;
            case DOWN:
            {
                if(segments[i]->yOffset > -0.95f) {
                    segments[i]->yOffset -= 0.001f;
                }
            } break;
        }
        if(i >0) {
            segments[i]->direction = segments[i-1]->direction;
        }
       }
       
   }  


   bool CheckCollision(FoodEntity* food)
   {
       float distance = sqrt(pow(food->xOffset - segments[0]->xOffset, 2) + pow(food->yOffset - segments[0]->yOffset, 2));
       //If our boxes overlap
       if(distance < (radius + food->radius))
       {
           //TODO(Tanner): Add a link to the tail
            AddSegment();
           //TODO(Tanner): Increment the length;

           return true;
       }
       else
       {
           return false;
       }
   }

   void AddSegment()
   {
       //TODO(Tanner): Change this to use my own MemoryManager
        segments[length] = (snake_node*)malloc(sizeof(snake_node));
        
        segments[length]->xOffset = segments[length-1]->xOffset;
        segments[length]->yOffset = segments[length-1]->yOffset;
        segments[length]->direction = segments[length-1]->direction;

        switch(segments[length-1]->direction)
        {
            case LEFT:
            {
                segments[length]->xOffset -= .05f;
            } break;
            case UP:
            {
                segments[length]->yOffset -= .05f;
            } break;
            case RIGHT:
            {
                segments[length]->xOffset += .05f;
            } break;
            case DOWN:
            {
                segments[length]->yOffset += .05f;
            } break;
        }
        length++;

   }


};




#endif