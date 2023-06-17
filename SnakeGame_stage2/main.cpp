#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <thread>

#include "snakegame.h"
#include "map.h"
#include "snake.h"
using namespace std;

// visibility
// design patterns - singleton
int main() {

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0); // Delete cursers

    int map_height, map_width;
    map_height = 22;
    map_width = 50;
    resize_term(map_height, map_width);

    start_color();
    init_pair(6, COLOR_GREEN, COLOR_GREEN); // background
    bkgd(COLOR_PAIR(6));
    
    // Item item;
    // item.getInstance();
    // Snake snake;
    // snake.getInstance();

    SnakeGame snakeGame(map_height, map_width);
    snakeGame.gameStart();

    timeout(10000);
    getch();

    return 0;
}