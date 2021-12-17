#ifndef DEF_SNAKE_ENTITY_H
#define DEF_SNAKE_ENTITY_H



#include "ShaderLoader.h"
#include "FoodEntity.h"
#include <math.h>
const int STARTSIZE = 5;
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
       for(int i = 0; i < STARTSIZE; i++ )
       {
            segments[i] = (snake_node*)malloc(sizeof(snake_node));
            segments[i]->yCoord = 7;
            segments[i]->xCoord = 7 - i;
            segments[i]->direction = RIGHT;
       }
       
       length = STARTSIZE;
   }

   void SetDirection(Direction d) 
   {
       Direction currDir = segments[0]->direction;
       if(  !(currDir == RIGHT && d == LEFT) &&
            !(currDir == UP && d == DOWN)  &&
            !(currDir == LEFT && d == RIGHT) &&
            !(currDir == DOWN && d == UP)
         )
        {
            segments[0]->direction = d;
        }
       
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
               else
               {
                   segments[0]->xCoord = TABLESIZE-1;
               }
           } break;
           case UP:
           {
               if(segments[0]->yCoord > 0)
               {
                   segments[0]->yCoord--;
               }
               else
               {
                   segments[0]->yCoord = TABLESIZE-1;
               }
           } break;
           case RIGHT:
           {
               if(segments[0]->xCoord < TABLESIZE - 1)
               {
                   segments[0]->xCoord++;
               }
               else
               {
                   segments[0]->xCoord = 0;
               }
           } break;
           case DOWN:
           {
               if(segments[0]->yCoord < TABLESIZE - 1)
               {
                   segments[0]->yCoord++;
               }
               else
               {
                   segments[0]->yCoord = 0;
               }
           } break;

       }       
       
   }  


   bool CheckCollision(FoodEntity* food)
   {
        if(segments[0]->xCoord == food->xCoord &&
           segments[0]->yCoord == food->yCoord)
        {
            AddSegment();
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
        
        segments[length]->xCoord = segments[length-1]->xCoord;
        segments[length]->yCoord = segments[length-1]->yCoord;
        segments[length]->direction = segments[length-1]->direction;

        switch(segments[length-1]->direction)
        {
            case LEFT:
            {
                segments[length]->xCoord -= 1;
            } break;
            case UP:
            {
                segments[length]->yCoord -= 1 ;
            } break;
            case RIGHT:
            {
                segments[length]->xCoord += 1;
            } break;
            case DOWN:
            {
                segments[length]->yCoord += 1;
            } break;
        }
        length++;
        
   }


};




#endif