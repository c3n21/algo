#include "item.h"
#include <malloc.h>
#include <stdio.h>
#include "../../../debug.h"

#undef ITEM_TYPE
#define ITEM_TYPE int

struct s_item {
        ITEM_TYPE element;
        Key key;
};

Item item_new(void * e) {
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
        key_delete(item->key);
        free(item);
}

int item_compare(Item item1, Item item2) {
        int res = 0; //equals
        debug_print("[item_compare] ");
        item_print(item1);
        printf(" ");
        item_print(item2);
        printf("\n");

        if (item1 == item2 && item1 == NULL) {
                debug_print("[item_compare] item1 & item2 are NULL\n");
                return res;
        }

        if (item1 == NULL) {
                debug_print("[item_compare] item1 is NULL\n");
                return 1;
        }

        if (item2 == NULL) {
                debug_print("[item_compare] item2 is NULL\n");
                return -1;
        }
        
        if (item1->element < item2->element) {
                debug_print("[item_compare] item1 is less than item2\n");
                return -1;
        }

        if (item1->element > item2->element) {
                debug_print("[item_compare] item1 is greater than item2\n");
                return 1;
        }

        return  res;
}

Key item_key(Item item) {
        return item->key;
}
