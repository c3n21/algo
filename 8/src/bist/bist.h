#ifndef BIST_H
#define BIST_H
#include "bit/bit.h"

/**
 * Creators
 */
Bit_node bist_new(Item item);

/**
 * Destructors
 */
int bist_delete( Bit_node *r, Key k );

Item bist_min(Bit_node p);
Item bist_max(Bit_node p);

/*stampa  in  ordine  inverso:*/
void bist_orderprint(Bit_node p);

/*stampa  in  ordine  inverso:*/
void bist_invorderprint(Bit_node p);
void bist_insert( Bit_node *q, Item  item );

/**
 * Searching
 */
Item bist_search(Bit_node p, Key k);
int bist_searchparent(Bit_node, Key, Bit_node *, Bit_node *);
#endif
