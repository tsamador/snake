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
    int xCoord;
    int yCoord;
    Direction direction;
};


struct SnakeEntity {

   ShaderLoader* _shader;
   snake_node** segments;
   int VAO;
   int length;

   SnakeEntity() {
       segments = (snake_node**)malloc(sizeof(snake_node*)*50);
       segments[0] = (snake_node*)malloc(sizeof(snake_node));
       segments[0]->yCoord = 7;
       segments[0]->xCoord = 7;
       segments[0]->direction = RIGHT;
       length = 1;
   }

   void SetDirection(Direction d) 
   {
       segments[0]->direction = d;
   }

   void Update() 
   {
    
       for(int i = length - 1; i > 0; i--)
       {
           segments[i]->xCoord = segments[i-1]->xCoord;
           segments[i]->yCoord = segments[i-1]->yCoord;
       }
       
       switch(segments[0]->direction)
       {
           //TODO(Tanner): Do I want to lose if i hit the edge, or wrap???
           case LEFT:
           {
               if(segments[0]->xCoord > 0)
               {
                   segments[0]->xCoord--;
               }
           } break;
           case UP:
           {
               if(segments[0]->yCoord > 0)
               {
                   segments[0]->yCoord--;
               }
           } break;
           case RIGHT:
           {
               if(segments[0]->xCoord < TABLESIZE - 1)
               {
                   segments[0]->xCoord++;
               }
           } break;
           case DOWN:
           {
               if(segments[0]->yCoord < TABLESIZE - 1)
               {
                   segments[0]->yCoord++;
               }
           } break;

       }       
       
   }  


   bool CheckCollision(FoodEntity* food)
   {
       return false;
   }

   void AddSegment()
   {
       /*
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
*/
   }


};




#endif