#include "item.h"

void Item::init(int height, int width) {
    this->height = height;
    this->width = width;

    timer = 10;
    srand(time(NULL));
}
int Item::update() {
    int new_item = 0;
    int item_x, item_y, select_item;

    if ( timer < 0 ) { // Timer of item 
        timer=20;
        if (last_item_number==growth)
            new_item = delete_growth;
        if (last_item_number==poison)
            new_item = delete_poison;
    }

    else if ((growth_x.size() + poison_x.size()) < 3) { // Up to 3 items can appear (n tick -> 1 items)
        // Random coordinate which will be appeared item
        item_x = (rand()%(height-2) +1); // %(map.height-3)+2
        item_y = (rand()%(width-2) +1); // %(map.width-3)+2
        // Select item number
        select_item = rand()%2 + growth;
        // Case growth
        if (select_item == growth) {
            growth_x.push_front(item_x);
            growth_y.push_front(item_y);
            last_item_number = growth;
        }
        // Case poison
        else if (select_item == poison) {
            poison_x.push_front(item_x);
            poison_y.push_front(item_y);
            last_item_number = poison;
        }
        new_item = select_item;
    }
    return new_item;
}