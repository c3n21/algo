#ifndef ITEM_H
#define ITEM_H

typedef struct s_item * Item;

Item item_new(int value);
int item_compare(Item, Item);
void item_print(Item);
#endif
