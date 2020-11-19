#include "bist.h"
#include "bit/bit.h"
#include <stdio.h>

struct s_key {
        int n;
};

Item bist_min(Bit_node p);
Item bist_max(Bit_node p);

/*stampa  in  ordine  inverso:*/
void bist_orderprint(Bit_node p);

/*stampa  in  ordine  inverso:*/
void bist_invorderprint(Bit_node p);
Item bist_search(Bit_node r, Key k);

void bist_insert(Bit_node *q, Item item){
        Bit_node cur = *q; 
        Item cur_it  = bit_item(cur);
};

int bist_delete(Bit_node *r, Key k);

Bit_node bist_new(Item item) {
        Bit_node new = bit_new(item);
        return new;
};
