#include <stdio.h>
#include <stdlib.h>
#include "../src/bist/bit/bit.h"
#include "test.h"

#define TEST_SIZE 15

int main(int argc, char * args[]) {
        Bit_node root = NULL;
        Item items[TEST_SIZE];

        createItems(items, TEST_SIZE);
        createBit(items, TEST_SIZE, &root);
        printf("[PRINTING SUMMARY]\n");
        bit_printassummary(root, 0);
        return 0;
}
