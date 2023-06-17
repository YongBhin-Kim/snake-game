#include "map.h"

Map::Map(int height, int width){//:road(0), wall(1), immute_wall(2) {

    this->height = height;
    this->width = width;

    // Allocation member variable map
    map = new int*[height];
    for (int i=0; i<height; i++)
        map[i] = new int[width];

}
void Map::init() {

    down = 0; up = 1; left = 2; right = 3;
    direction = left;

    for (int h=0; h<height; h++) {
        for (int w=0; w<width; w++) {
            map[h][w] = road;
            if (h==0 || w==0 || h==(height-1) || w==(width-1)) {
                map[h][w] = wall;
                if (h==0 || h==(height-1)) {
                    if (w==0 || w==(width-1))
                        map[h][w] = immute_wall;
                }
            }
        }
    }
}
void Map::print() {
    init_pair(1, COLOR_WHITE, COLOR_WHITE); // default(0)
    init_pair(2, COLOR_CYAN, COLOR_CYAN); // wall(1)
    init_pair(3, COLOR_BLACK, COLOR_BLACK); // Immune wall(2)
    init_pair(6, COLOR_BLUE, COLOR_BLUE); // Growth(5)
    init_pair(7, COLOR_RED, COLOR_RED); // Poison(6)

    for (int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            // Set & Print color
            switch (map[i][j]) {
                case 0: // background
                    attron(COLOR_PAIR(1));
                    mvprintw(i, j,  " "); // 0
                    attroff(COLOR_PAIR(1));
                    break;
                case 1: // wall
                    attron(COLOR_PAIR(2));
                    mvprintw(i, j,  " "); // 1
                    attroff(COLOR_PAIR(2));
                    break;
                case 2: // Immune Wall
                    attron(COLOR_PAIR(3));
                    mvprintw(i, j,  " "); // 2
                    attroff(COLOR_PAIR(3));
                    break;
            }
        }
    }
    refresh();
}

int Map::getHeight() {
    return height;
}
int Map::getWidth() {
    return width;
}

