#ifndef ITEM_H
#define ITEM_H

#include "../key/key.h"
typedef struct s_item * Item;

Item item_new(void * e);
void item_print(Item item);
void item_delete(Item item);
int item_compare(Item item1, Item item2);
Key item_key(Item item);

#endif
