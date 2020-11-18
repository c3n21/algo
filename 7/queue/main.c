#include "debug.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

#define SIZE QUEUE_SIZE/2

int main (int argc, char *args[]) {
        Queue * q = queue();
        Item * item;
        for (int i = 0; i < SIZE; i++) {
                item = makeItem(i);
                enqueue(*q, *item);
                //print_queue(*q);
        }

        //        for (int i = 0; i < SIZE; i++) {
        //                *item = dequeue(*q);
        //                //printItem(*item);
        //                print_queue(*q);
        //        }

        *item = dequeue(*q);
        for (int i = 0; i < SIZE; i++) {
                item = makeItem(i);
                enqueue(*q, *item);
                //print_queue(*q);
        }
        //printItem(*item);
        print_queue(*q);
        return 0;
}

