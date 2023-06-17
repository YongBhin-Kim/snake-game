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
bool Snake::move() {
    // Snake coordinates
    int snake_head_x = snake_x[0];
    int snake_head_y = snake_y[0];

    // Snake가 벽을 만날 경우 게임 실패
    if (map[snake_head_x][snake_head_y] == wall) { // wall일 경우
        return false;
    }

    // Update snake head and body
    if (direction==right) snake_head_y++;
    if (direction==left) snake_head_y--;
    if (direction==down) snake_head_x++;
    if (direction==up) snake_head_x--;
    snake_x.push_front(snake_head_x);
    snake_y.push_front(snake_head_y);

    // Update snake tails
    snake_x.pop_back();
    snake_y.pop_back();
    
    // Move snake
    int keyboard;
    timeout(300);
    keyboard = getch(); // 몇 초 기다리게 하기
    switch (keyboard) {
        case KEY_LEFT: // Left 
            if (direction==right) return false;
            direction=left;
            break;
        case KEY_RIGHT: // Right
            if (direction==left) return false;
            direction=right;
            break;
        case KEY_UP: // Up
            if (direction==down) return false;
            direction=up;
            break;
        case KEY_DOWN: // Down
            if (direction==up) return false;
            direction=down;
            break;
        
    }
    usleep(tick*3);

    return true;
}