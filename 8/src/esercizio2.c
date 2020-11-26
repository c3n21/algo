#include <stdio.h>
#include "bist/bist.h"
#include "bist/bit/bit.h"
#include "bist/bit/item/item.h"
#include "debug/debug.h"
#include <execinfo.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
        void *array[10];
        size_t size;

        // get void*'s for all entries on the stack
        size = backtrace(array, 10);

        // print out all the frames to stderr
        fprintf(stderr, "Error: signal %d:\n", sig);
        backtrace_symbols_fd(array, size, STDERR_FILENO);
        exit(1);
}

#define ARRAY_SIZE 2

Bit_node createBit(Item * restrict items, const int size);
void createItems(Item * restrict items, const int size);

int main(int argc, char * args[]) {
        signal(SIGSEGV, handler);
        Item items[ARRAY_SIZE];

        createItems(items, ARRAY_SIZE);
        Bit_node root = createBit(items, ARRAY_SIZE);

        bit_printassummary(root, 0);

        return 0;
}

void createItems(Item * restrict items, const int size) {
        for (int i = 0; i < size; i++) {
                items[i] = item_new(&i);
        }
}

Bit_node createBit(Item * restrict items, const int size) {
        Bit_node root = NULL;
        for (int i = 0; i < size; i++) {
                if (root == NULL) {
                        root = bist_new(items[i]);
                } else {
                        bist_insert(&root, items[i]);
                }
        }

        return root;
}
