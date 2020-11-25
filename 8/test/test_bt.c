#include <stdio.h>
#include <stdlib.h>
#include "../src/bist/bist.h"

#define TEST_SIZE 15

int main(int argc, char * args[]) {
        Bit_node root = NULL;

        for (int i = 0; i < TEST_SIZE; i++) {
                int n = rand()%10;
                Item item = item_new(&n);
                if (root == NULL) {
                        root = bist_new(item);
                } else {
                        bist_insert(&root, item);
                }
                bit_printassummary(root, 0);
        }
//        int n = 0;
//        while (scanf("%d", &n) != EOF) {
//                Item item = item_new(&n);
//                if (root == NULL) {
//                        root = bist_new(item);
//                } else {
//                        bist_insert(&root, item);
//                }
//                bit_printassummary(root, 0);
//                
//        }
        return 0;
}
