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

    if (map[snake_head_x][snake_head_y] == 6) { // poison일 경우 snake 길이 감소
        snake_x.pop_back();
        snake_y.pop_back();
        map[snake_head_x][snake_head_y] = 0; // 먹은 아이템 제거
        if (snake_x.size() < 3) // snake 길이가 3 미만이면 게임 오버
            return false;

    }

    // Update snake head and body
    if (direction==right) snake_head_y++;
    if (direction==left) snake_head_y--;
    if (direction==down) snake_head_x++;
    if (direction==up) snake_head_x--;
    snake_x.push_front(snake_head_x);
    snake_y.push_front(snake_head_y);

    if (map[snake_head_x][snake_head_y] == 5) { // growth
        snake_x.push_front(snake_head_x);
        snake_y.push_front(snake_head_y);
        map[snake_head_x][snake_head_y] = 0; // 먹은 아이템 제거
        
    }


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
void Snake::update(Item &item) {
    int new_item, map_number, delete_x, delete_y;
    while (true) {
        item.timer--;
        new_item = item.update();
        // Item update를 받아서 map에 update
        // if : 업데이트될 아이템 종류 확인
        //  if : map의 해당 좌표 값이 0이라면 map에 아이템 적용
        //  else : map에 넣을 수 없으면 item 제거하고 재시도
        if (new_item == item.growth) {
            map_number = map[item.growth_x[0]][item.growth_y[0]];
            if (map_number == road) {
                map[item.growth_x[0]][item.growth_y[0]] = item.growth;
                break;
            }
            else {
                item.growth_x.pop_front();
                item.growth_y.pop_front();
            }
        }
        else if (new_item == item.poison) {
            map_number = map[item.poison_x[0]][item.poison_y[0]];
            if (map_number == road) {
                map[item.poison_x[0]][item.poison_y[0]] = item.poison;
                break;
            }
            else {
                item.poison_x.pop_front();
                item.poison_y.pop_front();
            }
        }
        else if (new_item == item.delete_growth) {
            map[item.growth_x.back()][item.growth_y.back()] = road;
            item.growth_x.pop_back();
            item.growth_y.pop_back();
            break;
            // map[delete_x][delete_y] = road;
        }
        else if (new_item == item.delete_poison) {
            map[item.poison_x.back()][item.poison_y.back()] = road;
            item.poison_x.pop_back();
            item.poison_y.pop_back();
            break;
            // map[delete_x][delete_y] = road;
        }
        else break; // 현재 item이 3개인 경우
    }
}
// 4단계를 구현을 안 했지만 알고리즘을 설계를 한다면 이런 방식으로 하면 될 것 같다
