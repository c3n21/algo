#include "item.h"
#include <malloc.h>
#include <stdio.h>
#include "../../../debug/debug.h"


struct s_item {
        ITEM_TYPE element;
        Key key;
        unsigned int inc;
};

Item item_new(void * e, void * key) {
        Item item = (Item) malloc(sizeof(struct s_item));
        item->element = *(ITEM_TYPE *) e;
        item->key = key_new(key);

        return item;
}

void item_print(Item item) {
        if (item != NULL) {
                printf("%d", item->element);
        }
}

void item_delete(Item item) {
        key_delete(item->key);
        free(item);
}

int item_compare(Item item1, Item item2) {
        debug_print("[item_compare] ");
        item_print(item1);
        printf(" ");
        item_print(item2);
        printf("\n");

        if (item1 != NULL && item2 != NULL) {
                if (item1->element == item2->element) {
                        debug_print("[item_compare] equals\n");
                        return 0;
                } 

                if (item1->element > item2->element) {
                        debug_print("[item_compare] item1 is greater than item2\n");
                        return 1;
                }

                if (item1->element < item2->element) {
                        debug_print("[item_compare] item1 is lesser than item2\n");
                        return -1;
                }

                debug_print("[item_compare] Error in comparation: not provided\n");
        }

        return -2;
}

ITEM_TYPE item_value(Item item) {
        return item->element;
}

Key item_key(Item item) {
        debug_print("[item_key] key = %p\n", item->key);
        return item->key;
}
