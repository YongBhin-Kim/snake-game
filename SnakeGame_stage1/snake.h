#ifndef SNAKE_H
#define SNAKE_H
#include "map.h"

class Snake : public Map {
public:
    // Coordinate of snake is (y, -x) in map
    deque<int> snake_x; // x coordinate of snake
    deque<int> snake_y; // y coordinate of snake

    Snake(int height=0, int width=0);

    void init();
    void print();
    bool move();

};
#endif