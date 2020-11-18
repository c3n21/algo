/**
 * [OVERVIEW]
 *      implementazione di una coda usando array circolari
 */

#include "debug.h"
#include "queue.h"
#include <malloc.h>
#include <stdio.h>

struct s_queue {
        Item * items;
        unsigned int rear;
        unsigned int front;
        unsigned int size;
};

struct s_item {
        int el;
};

Queue * queue() {
        Queue * new_queue   = (Queue *) malloc(sizeof(Queue));
        (*new_queue)        = (struct s_queue *) malloc (sizeof(struct s_queue));
        (*new_queue)->rear  = 0;
        (*new_queue)->front = 0;
        (*new_queue)->size  = 0;
        (*new_queue)->items = (Item *) malloc(sizeof(Item) * QUEUE_SIZE);

        return new_queue;
}

// Put element on rear
void enqueue ( Queue queue , Item item ) {
        if (queue->size < QUEUE_SIZE) {
                queue->items[queue->rear] = item;
                debug_print("[DEBUG] queue-circular::enqueue \nitem = %p, size = %d\n", queue->items[queue->rear], queue->size);

                queue->rear = (queue->rear + 1) % QUEUE_SIZE;
                debug_print("[DEBUG] queue-circular::enqueue \nrear = %d, front = %d\n", queue->rear, queue->front);
                queue->size++;
        }
};
// Remove and return element from front
Item dequeue ( Queue queue ) {
        if (queue->size > 0) {
                queue->size--;
                debug_print("[DEBUG] queue-circular::dequeue \nrear = %d, front = %d\n", queue->rear, queue->front);
                Item * item = &queue->items[queue->front];
                
                debug_print("[DEBUG] queue-circular::enqueue \nItem = %d\n", (*item)->el);
                queue->front = (queue->front + 1) % QUEUE_SIZE;
                debug_print("[DEBUG] queue-circular::dequeue \n new front = %d\n", queue->front);
                return *item;
        }

        Item res;

        return res;
};

// Return front element
Item frontValue ( Queue queue ) {
        if (queue->size > 0) {
                return queue->items[queue->front];
        }

        Item res;

        return res;
};
// Check if queue is empty
int is_empty_queue ( Queue queue ) {
        return queue->size == 0;
};

// Print queue content
void print_queue ( Queue queue ) {
        for (int i = 0, front = queue->front; i < queue->size; i++, front = (front+1) % QUEUE_SIZE) {
                printf("i = %d, item = %d\n", i, (*queue).items[front]->el);
        }
};


Item * makeItem (int n) {
        Item * new_item = (Item *) malloc(sizeof(Item));
        (*new_item)     = (struct s_item *) malloc(sizeof(struct s_item));
        (*new_item)->el = n;
        return new_item;
}

void printItem(Item item) {
        printf("item = %d\n", item->el);
}
