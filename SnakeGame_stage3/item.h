#ifndef ITEM_H
#define ITEM_H
#include "map.h"

class Item {
    int height; // height of map
    int width; // width of map
public:
    // Coordinate of item is (y, -x) in map
    deque<int> growth_x; // x coordinates of growth items
    deque<int> growth_y; // y coordinates of growth items
    deque<int> poison_x; // x coordinates of poison items
    deque<int> poison_y; // y coordinates of poison items

    int timer;
    int last_item_number;
    const static int growth = 5;
    const static int poison = 6;
    const static int delete_growth = 15;
    const static int delete_poison = 16;

    void init(int height, int width);
    int update();
};

// [item]
// gate를 랜덤하게 받고

// [move]
// snake_x, snake_y
// 

#endif