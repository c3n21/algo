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

void heapify_down(Pqueue queue, int current);

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
void pqueue_insert (Pqueue queue, Item item) {
        if (queue->count < queue->size) {
                queue->h[queue->count] = item;
                heapify_up(queue, queue->count++);
        }
};
/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin (Pqueue queue) {
        Item last = queue->h[1];
        if (queue->count > 0) {
                queue->count--;
        }
        return last;
}
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min (Pqueue queue) {
        return queue->h[1];
}

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

void heapify_down(Pqueue queue, int current) {
        if (2*current <= queue->size) {
                int left  = 2*current;
                int right = (right = (2*current) + 1) <= queue->size? right : left; //no figlio destro

                if (item_compare(queue->h[left], queue->h[right]) == -1) { //left è più piccolo di destro
                        queue->h[current] = queue->h[left];
                        heapify_down(queue, left);
                } else { //left è più grande o uguale
                        queue->h[current] = queue->h[right];
                        heapify_down(queue, right);
                }
        }
}
