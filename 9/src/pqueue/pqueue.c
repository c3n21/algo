#include "../../include/pqueue.h"
#include <malloc.h>

struct pqueue {
        Heap h;
        int size , count ;
};

/**
 * PROTOTYPES
 */

void heapify_up(Pqueue queue, int last);

void heapify_down(Pqueue queue);

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new (int n) {
        Pqueue new = (Pqueue) malloc(sizeof(struct pqueue)+1);
        new->h     = (Heap) malloc(sizeof(Item)*n);

        for (int i = 0; i < n; i++) {
                new->h[i] = NULL;
        }

        new->count = 0;
        new->size  = n;
        return new;
};

/* distrugge la coda di priorità */
void pqueue_destroy (Pqueue queue) {
        free(queue->h);
        free(queue);
};
/* restituisce la lunghezza della coda di priorità */
int pqueue_length (Pqueue queue) {
        return queue->count;
};

/* inserisce l’Item nella coda di priorità */
void pqueue_insert ( Pqueue queue, Item item) {
        if (queue->count < queue->size) {
                queue->h[queue->count] = item;
                heapify_up(queue, queue->count++);
        }
};
/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin ( Pqueue );
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min ( Pqueue );

void heapify_up(Pqueue queue, int current) {
        if (current > 1) {

                int parent = current/2;

                if (item_compare(queue->h[parent], queue->h[current]) > 0) { //father is bigger than current, so swap them
                        Item tmp = queue->h[current];
                        queue->h[current] = queue->h[parent];
                        queue->h[parent] = tmp;
                }
                heapify_up(queue, parent);
        }
}

void heapify_down(Pqueue queue) {
}
