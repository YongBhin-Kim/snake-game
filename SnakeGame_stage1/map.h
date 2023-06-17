#ifndef MAP_H
#define MAP_H

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <unistd.h>

using namespace std;

class Map {
protected:
    int **map; // map array
    int height; // height of map
    int width; // width of map

public:

    const static int tick = 100000;
    const static int road = 0;
    const static int wall = 1;
    const static int immute_wall = 2;


    Map(int height=0, int width=0);
    // virtual ~Map();
    virtual void init();
    virtual void print();
    int getHeight();
    int getWidth();
};


#endif