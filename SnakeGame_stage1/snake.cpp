#include "snake.h"

Snake::Snake(int height, int width): Map(height, width) {
    // Initialize of Map and snake is proceed in Snake::init function
}
void Snake::init() {
    Map::init();

    // Init snake place
    for (int i=0; i<3; i++) {
        snake_x.push_back(height/2);
        snake_y.push_back(height/2+i);
    }
}
void Snake::print() {
    Map::print();

    init_pair(4, COLOR_YELLOW, COLOR_YELLOW); // Snake head
    init_pair(5, COLOR_GREEN, COLOR_GREEN); // Snake body

    // Print snake head
    attron(COLOR_PAIR(4));
    mvprintw(snake_x[0], snake_y[0], " "); // 3
    attroff(COLOR_PAIR(4));
 
    // Print snake body 
    for(int i=1; i<snake_x.size();i++) {
        attron(COLOR_PAIR(5));
        mvprintw(snake_x[i], snake_y[i], " "); // 4
        attroff(COLOR_PAIR(5));
    }
    refresh();
}