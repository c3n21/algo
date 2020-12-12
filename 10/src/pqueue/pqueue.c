#include "../../include/pqueue.h"
#include "../../include/item.h"
#include "../../include/debug.h"
#include <stdio.h>
#include <stdlib.h>

#include <malloc.h>

struct pqueue {
        Heap h;
        int size , count ;
};

struct s_item {
        int value;      
}; 
/**
 * PROTOTYPES
 */
static void printQueue(Pqueue queue);

static void heapify_up(Pqueue queue, int last);

static void heapify_down(Pqueue queue, int current);

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new (int n) {
        Pqueue new = malloc(sizeof(struct pqueue));
        new->h     = malloc(sizeof(Item)*n + 1);

        for (int i = 0; i < n; i++) {
                new->h[i] = NULL;
        }

        new->count = 0;
        new->size  = n;
        return new;
}

/* distrugge la coda di priorità */
void pqueue_destroy (Pqueue queue) {
        free(queue->h);
        free(queue);
}

/* restituisce la lunghezza della coda di priorità */
int pqueue_length (Pqueue queue) {
        return queue->count;
}

/* inserisce l’Item nella coda di priorità */
void pqueue_insert (Pqueue queue, Item item) {
        debug_print("[pqueue_insert] count = %d <= size = %d\n", queue->count, queue->size);
        if (queue->count <= queue->size) {
                //printQueue(queue);
                queue->h[++queue->count] = item; //count = size+1
                debug_print("[pqueue_insert] new count = %d\n", queue->count);
                //debug_print("[pqueue_insert] after\n");
                heapify_up(queue, queue->count);
                printQueue(queue);
        }
}

/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin (Pqueue queue) {
        Item min = NULL;
        if (queue->count > 0) {
                min = queue->h[1];
                queue->h[1] = NULL;
                heapify_down(queue, 1);
                queue->count--;
        }

        debug_print("[pqueue_extractmin] printing queue\n");
        printQueue(queue);

        return min;
}
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min (Pqueue queue) {
        return queue->h[1];
}

static void heapify_up(Pqueue queue, int current) {
        debug_print("[pqueue::static::heapify_up] printing heap, current = %d\n", current);

        if (current > 1) { //il current non è 
                int parent = current/2;

                if (item_compare(queue->h[parent], queue->h[current]) > 0) { //father is bigger than current, so swap them
                        Item tmp = queue->h[current];
                        queue->h[current] = queue->h[parent];
                        queue->h[parent] = tmp;
                }
                printQueue(queue);
                heapify_up(queue, parent);
        }
}

static void heapify_down(Pqueue queue, int current) {
        debug_print("[pqueue::static::heapify_down] printing heap, current = %d\n", current);

        int left = 2*current;
        if (left <= queue->size) { //ha almeno un figlio
                int right = left + 1;
                if (right > queue->size) { //nessun figlio destro
                        right = left;
                }

                debug_print("[pqueue::static::heapify_down] left = %d, right = %d\n", left, right, current);

                Item tmp = queue->h[current];

                if (item_compare(queue->h[left], queue->h[right]) == -1) { //left è più piccolo di destro
                        queue->h[current] = queue->h[left];
                        queue->h[left]    = tmp;
                        //printQueue(queue);
                        heapify_down(queue, left);
                } else { //left è più grande o uguale
                        queue->h[current] = queue->h[right];
                        queue->h[right]   = tmp;
                        //printQueue(queue);
                        heapify_down(queue, right);
                }
        }
}

void pqueue_sort(Item * a, int l, int r) {
        Pqueue q = pqueue_new((r - l)-1);
        for (int i = l; i < r; i++) {
                debug_print("[pqueue_sort] inserting new element, i = %d, r = %d, ", i, r);
                item_print(a[i]);
                pqueue_insert(q, a[i]);
        }
        
        debug_print("[pqueue_sort] COMINCIO ESTRAZIONE\n\n");
        printQueue(q);

        for (int i = l; i < r; i++) {
                debug_print("[pqueue_sort] extracting, i = %d\n", i);
                a[i] = pqueue_extractmin(q);
                item_print(a[i]);
        }
}

Item item_new(int value) {
        Item item   = malloc(sizeof(struct s_item));
        item->value = value;

        debug_print("[item_new] value = %d\n", value);

        return item;
}

int item_compare(Item item1, Item item2) {
        if (item1 == item2) {
                return 0;
        }

        if (item1 == NULL) {
                return -1;
        }

        if (item2 == NULL) {
                return 1;
        }
        
        if (item1->value == item2->value) {
                return 0;
        }

        debug_print("[item_compare] item1 = %d, item2 = %d\n", item1->value, item2->value);

        if (item1->value > item2->value) {
                return 1;
        }


        if (item1->value < item2->value) {
                return -1;
        }

        debug_print("[item_compare] unknown error! item1 = %p, item2 = %p\n", item1, item2);
        exit(1);
}

void item_print(Item item) {
        if (item != NULL) {
                printf("item : %d\n", item->value);
        } else {
                printf("item : NULL\n");
        }
}

static void printQueue(Pqueue queue) {
        debug_print("[pqueue::static::printQueue] printing...\n");
        for (int i = 1; i <= queue->count; i++) {
                printf("[%d] = ", i);
                item_print(queue->h[i]);
        }
}
