#ifndef PQUEUE_H
#define PQUEUE_H
#include "item.h"

typedef struct pqueue * Pqueue ;
typedef Item * Heap ;

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new ( int n );
/* distrugge la coda di priorità */
void pqueue_destroy ( Pqueue );
/* restituisce la lunghezza della coda di priorità */
int pqueue_length ( Pqueue );
/* inserisce l’Item nella coda di priorità */
void pqueue_insert ( Pqueue , Item );
/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin ( Pqueue );
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min ( Pqueue );
#endif
