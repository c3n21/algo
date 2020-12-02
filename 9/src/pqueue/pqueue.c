#include "../../include/pqueue.h"
#include <malloc.h>

struct pqueue {
        Heap h;
        int size , count ;
};

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new (int n) {
        Pqueue new = (Pqueue) malloc(sizeof(struct pqueue));
        new->h     = (Heap) malloc(sizeof(Item)*n);
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
int pqueue_length ( Pqueue ) {
};
/* inserisce l’Item nella coda di priorità */
void pqueue_insert ( Pqueue , Item );
/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin ( Pqueue );
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min ( Pqueue );
