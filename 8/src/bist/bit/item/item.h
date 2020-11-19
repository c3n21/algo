#ifndef ITEM_H
#define ITEM_H

#define ITEM_TYPE void

typedef struct s_item * Item;

Item item_new(ITEM_TYPE * e);
void item_print(Item item);
void item_delete(Item item);
int item_compare(Item item1, Item item2);

#endif
