#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <unistd.h>

#include <thread>
#include <future>
#include <chrono>


#include "map.h"
#include "snake.h"
using namespace std;

class SnakeGame {
public:
    Snake snake;
    SnakeGame(int height=0, int width=0);

    void gameStart();
};

#endif
