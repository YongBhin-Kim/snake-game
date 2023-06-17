#include "map.h"
#include "snakegame.h"
using namespace std;

SnakeGame::SnakeGame(int height, int width) {
    Snake newSnake(height, width);
    snake = newSnake;
}
void SnakeGame::gameStart() {
    snake.init();
    item.init(snake.getHeight(), snake.getWidth()); 

    while(true) {
        // Print map with snake
        snake.print();

        // Update items
        snake.update(item);

        if (snake.move() == false) {
            gameOver();
            break;
        }
    }
}
void SnakeGame::printFail() {
    init_pair(10, COLOR_RED, COLOR_BLACK); // Snake head

    // Print fail context
    attron(COLOR_PAIR(10));
    mvprintw(snake.getHeight()/2,   snake.getWidth()/2, " Game Over!!!            ");
    mvprintw(snake.getHeight()/2+1, snake.getWidth()/2, " Game Over!!!            ");
    mvprintw(snake.getHeight()/2+2, snake.getWidth()/2, " Game Over!!!            ");
    mvprintw(snake.getHeight()/2+3, snake.getWidth()/2, " Please enter any key... ");
    attroff(COLOR_PAIR(10));
    refresh();
}
void SnakeGame::gameOver() {
    printFail();
    // getch();
}