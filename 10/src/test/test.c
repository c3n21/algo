#include "../../include/test.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int createItems(Item * items, int * input, int size) {
        srand(time(NULL));
        
        if (input == NULL) {
                for (int i = 0; i < size; i++) {
                        items[i] = item_new(rand()%RANGE); 
                }
        } else {
                for (int i = 0; i < size; i++) {
                        items[i] = item_new(input[i]); 
                }
        }

        return 1;
}

void printItems(Item *items, int size) {
        for (int i = 0; i < size; i++) {
                item_print(items[i]);
        }
}
