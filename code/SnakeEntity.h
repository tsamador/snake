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
    snake_node* next;
};



struct SnakeEntity {

   ShaderLoader* _shader;
   Direction _direction;
   snake_node* _head;
   snake_node* _tail;
   float radius;
   int VAO;

   SnakeEntity() {
       _head = (snake_node*)malloc(sizeof(snake_node));
       radius = 0.02f;
       _head->xOffset = 0.0f;
       _head->yOffset = 0.0f;
   }

   void SetDirection(Direction d) 
   {
       _direction = d;
   }

   void Update() 
   {
       switch(_direction) 
       {
           case LEFT: 
           {
               if(_head->xOffset > -0.95f) {
                    _head->xOffset -= 0.001f;
               }
           } break;
           case UP: 
           {
               if(_head->yOffset < 0.95f) {
                    _head->yOffset += 0.001f;
               }
           } break;
           case RIGHT: 
           {
               if(_head->xOffset < 0.95f) {
                    _head->xOffset += 0.001f;
               }
           } break;
           case DOWN:
           {
               if(_head->yOffset > -0.95f) {
                   _head->yOffset -= 0.001f;
               }
           }
       }
   }    

   bool CheckCollision(FoodEntity* food)
   {
       float distance = sqrt(pow(food->xOffset - _head->xOffset, 2) + pow(food->yOffset - _head->yOffset, 2));
       //If our boxes overlap
       if(distance < (radius + food->radius))
       {
           //TODO(Tanner): Add a link to the tail

           //TODO(Tanner): Increment the length;

           return true;
       }
       else
       {
           return false;
       }
   }


};




#endif