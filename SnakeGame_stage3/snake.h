#ifndef SNAKE_H
#define SNAKE_H
#include "map.h"
#include "item.h"

class Snake : public Map {
    // Coordinate of snake is (y, -x) in map
    deque<int> snake_x; // x coordinate of snake
    deque<int> snake_y; // y coordinate of snake

public:
    Snake(int height=0, int width=0);

    void init();
    void print();
    bool move();

    void update(Item &item);

};
#endif