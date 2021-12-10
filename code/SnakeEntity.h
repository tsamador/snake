#ifndef DEF_SNAKE_ENTITY_H
#define DEF_SNAKE_ENTITY_H

#include "ShaderLoader.h"

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
   int VAO;

   SnakeEntity(ShaderLoader* shader ) {
       _shader = shader;
       _head = (snake_node*)malloc(sizeof(snake_node));
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


};




#endif