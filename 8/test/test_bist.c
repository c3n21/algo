#include <stdio.h>
#include "test.h"
#include "../src/bist/bist.h"

#define ARRAY_SIZE 10

int main(int argc, char * args[]) {
        Item items[ARRAY_SIZE];
        Bist root = NULL;

        createItems(items, ARRAY_SIZE);
        createBit(items, ARRAY_SIZE, &root);

        printf("[PRINTING SUMMARY]\n");
        bit_printassummary(bist_root(root), 0);

        return 0;
}
