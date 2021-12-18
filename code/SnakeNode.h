#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

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

#endif