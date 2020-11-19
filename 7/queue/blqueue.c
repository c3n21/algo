#include "queue.h"
#include "debug.h"
#include <stdio.h>
#include "blist.h"

void printItem(Item item) {
        printf(item->fmt, item->el);
        printf("\n");
}
