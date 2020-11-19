#include "item.h"
#include <malloc.h>
#include <stdio.h>

#undef ITEM_TYPE
#define ITEM_TYPE int

struct s_item {
        ITEM_TYPE element;
};

Item item_new(void *e) {
        Item item = (Item) malloc(sizeof(struct s_item));
        item->element = *(ITEM_TYPE *) e;

        return item;
}

void item_print(Item item) {
        if (item != NULL) {
                printf("%d", item->element);
        }
}

void item_delete(Item item) {
        free(item);
}

int item_compare(Item item1, Item item2) {
        int res = 0; //equals
        
        if (item1->element < item2->element) {
                res = -1;
        }

        if (item1->element > item2->element) {
                res = 1;
        }

        return  res;
}
