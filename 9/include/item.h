#ifndef ITEM_H
#define ITEM_H

typedef struct s_item {
        int value;      
} * Item;

int item_compare(Item, Item);
#endif
