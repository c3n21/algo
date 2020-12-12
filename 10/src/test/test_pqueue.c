#include <stdio.h>
#include "../../include/pqueue.h"
#include "../../include/test.h"
#include "../../include/pqueue.h"
#include "../../include/debug.h"

#define ITEMS_SIZE 5

int main(int argc, char * args[]) {
        Item items[ITEMS_SIZE];
        int input[ITEMS_SIZE];

        for (int i = 0; i < ITEMS_SIZE; i++) {
                scanf("%d", &input[i]);
        }

        debug_print("[CREATING ITEMS]\n\n\n");
        createItems(items, input, ITEMS_SIZE);

        debug_print("[PRINTING ITEMS]\n\n\n");
        printItems(items, ITEMS_SIZE);

        debug_print("[SORTING ITEMS]\n\n\n");
        pqueue_sort(items, 0, ITEMS_SIZE);

        debug_print("[PRINTING ITEMS]\n\n\n");
        printItems(items, ITEMS_SIZE);
        return 0;
}
