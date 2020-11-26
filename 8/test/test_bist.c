#include <stdio.h>
#include "test.h"
#include "../src/debug/debug.h"
#include "../src/bist/bist.h"

#define ARRAY_SIZE 10


int main(int argc, char * args[]) {
        Item items[ARRAY_SIZE];
        Bist root = NULL;

#ifdef DEBUG
        printf("[DEBUG flag enabled]\n");
#endif
        createItems(items, ARRAY_SIZE);
        createBist(items, ARRAY_SIZE, &root);

        printf("[PRINTING SUMMARY]\n");
        bit_printassummary(bist_root(root), 0);

        return 0;
}
