#include "test.h"
#include <stdio.h>
#include "../src/bist/bist.h"
#include <stdlib.h>
#include <time.h>

void createItems(Item * restrict items, const int size) {
        srand(time(NULL));

        for (int i = 0; i < size; i++) {
                int n = rand()%15;
                items[i] = item_new(&n, &n);
        }
}

int createBit(Item * restrict items, const int size, Bist * root) {
        for (int i = 0; i < size; i++) {
                if (*root == NULL) {
                        *root = bist_new(items[i]);
                } else {
                        bist_insert(*root, items[i]);
                }
        }

        return 1;
}

