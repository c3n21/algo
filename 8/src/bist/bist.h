#ifndef BIST_H
#define BIST_H
#include "bit/bit.h"

typedef struct s_bist * Bist;

/**
 * Creators
 */
Bist bist_new(Item);

/**
 * Destructors
 */
int bist_delete(Bist, Key);

Bit_node bist_root(Bist);

Item bist_min(Bist);
Item bist_max(Bist);

/*stampa  in  ordine  inverso:*/
void bist_orderprint(Bist);

/*stampa  in  ordine  inverso:*/
void bist_invorderprint(Bist);
int bist_insert(Bist, Item);

/**
 * Searching
 */
Item bist_search(Bist, Key);
int bist_searchparent(Bist, Key, Bist *, Bist *);
#endif
