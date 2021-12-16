#ifndef DEF_FOOD_ENTITY_H
#define DEF_FOOD_ENTITY_H

#include <stdlib.h>
#include <ctime>


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

    void update(bool result)
    {
        if(result)
        {
            Spawn();
        }
    }

    void Spawn()
    {
        xCoord = rand() % TABLESIZE;
        yCoord = rand() % TABLESIZE;
    }

};

#endif