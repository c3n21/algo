#include "bist/bist.h"
#include "bist/bit/bit.h"
#include "bist/bit/item/item.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

Bit_node createBit(Item * restrict items, const int size);

int main(int argc, char * args[]) {
        srand(time(NULL));
        Item items[ARRAY_SIZE];
        
        for (int i = 0; i < ARRAY_SIZE; i++) {
                items[i] = item_new(&i);
        }

        Bit_node root = createBit(items, ARRAY_SIZE);
        bit_printassummary(root, 0);

        return 0;
}

Bit_node createBit(Item * restrict items, const int size) {
        Bit_node root = NULL;
        for (int i = 0; i < ARRAY_SIZE; i++) {
                if (root == NULL) {
                        root = bit_new(items[i]);
                } else {
                        bist_insert(&root, items[i]);
                }

                item_delete(items[i]);
        }

        return root;
}
