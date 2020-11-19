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
