#include "blist.h"
#include "queue.h"
#include <stdio.h>

#define TEST_SIZE 10
int main(int argc, char * args[]) {
        BList l = BList_new();
        Item item;

        for (int i = 0; i < TEST_SIZE; i++) {
                item = makeItem(i);
                BList_append(l, item);
        }

        BList_print(l);
        return 0;
}
