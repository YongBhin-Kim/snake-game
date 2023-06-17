#include "map.h"
#include "snakegame.h"
using namespace std;

SnakeGame::SnakeGame(int height, int width) {
    Snake newSnake(height, width);
    snake = newSnake;
}
void SnakeGame::gameStart() {
    snake.init();
    snake.print();
}