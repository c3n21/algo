#include "../src/bist/bit/item/item.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOMNESS 200

Item randomfunc();

int main(int argc, char * args[]) {
        //int * n = (int *) malloc(sizeof(int));
        //*n = 3;
        srand(time(NULL));
        int n = 3;
        Item item = randomfunc();
        printf("item = ");
        item_print(item);
        for (int i = 0; i < RANDOMNESS; i++) {
                free(randomfunc());
        }
        printf("item = ");
        item_print(item);
        return 0;
}

Item randomfunc() {
        int n = rand();
        Item item = item_new(&n);
        
        return item;
}
