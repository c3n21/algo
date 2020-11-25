#ifndef ITEM_H
#define ITEM_H
#define ITEM_TYPE int

#include "../key/key.h"
typedef struct s_item * Item;

Item item_new(void *, void *);
void item_print(Item);
void item_delete(Item);
int item_compare(Item, Item);
int item_value(Item);
Key item_key(Item);

#endif
