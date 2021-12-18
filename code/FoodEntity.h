#ifndef DEF_FOOD_ENTITY_H
#define DEF_FOOD_ENTITY_H

#include <stdlib.h>
#include <ctime>
#include "SnakeNode.h"
#include "SnakeEntity.h"


//Generate a float between -0.95 and 0.95 


struct FoodEntity {
    int xCoord;
    int yCoord;
    ShaderLoader* _shader;
    int VAO;

    FoodEntity()
    {
        srand(time(0));
        xCoord = rand() % TABLESIZE;
        yCoord = rand() % TABLESIZE;
    }

    void Update(bool result, snake_node** segments, int snakeLength)
    {
        if(result)
        {
            Spawn(segments, snakeLength);
        }
    }

    void Spawn(snake_node** segments, int snakeLength)
    {
        //TODO(Tanner): Ensure respawn is not on top of snake
        bool colliding;
        do
        {
            xCoord = rand() % TABLESIZE;
            yCoord = rand() % TABLESIZE;
            colliding = false;
            for(int i = 0; i < snakeLength; i++)
            {
                if(xCoord == segments[i]->xCoord && yCoord == segments[i]->yCoord)
                {
                    colliding = true;
                }
            }

        }while(colliding);

    }

    

};

#endif