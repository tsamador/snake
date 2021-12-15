#ifndef DEF_FOOD_ENTITY_H
#define DEF_FOOD_ENTITY_H

#include <stdlib.h>
#include <ctime>


//Generate a float between -0.95 and 0.95 


struct FoodEntity {
    float xOffset;
    float yOffset;
    float radius;
    ShaderLoader* _shader;
    int VAO;

    FoodEntity()
    {
        srand(time(0));
        radius = 0.02f;
        xOffset = GenerateRandomFloat();
        yOffset = GenerateRandomFloat();
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
        xOffset = GenerateRandomFloat();
        yOffset = GenerateRandomFloat();
    }

    float GenerateRandomFloat()
    {
        //NOTE(Tanner): Not Entirely sure this will work 
        float x = (float)rand()/(float)(RAND_MAX/1.6f);
        return x-1;
    }
};

#endif