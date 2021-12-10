#ifndef DEF_SNAKE_ENTITY_H
#define DEF_SNAKE_ENTITY_H

#include "ShaderLoader.h"

enum Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

struct SnakeEntity {

   ShaderLoader* shader;
   Direction direction;
};

#endif