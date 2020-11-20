#include "bist.h"
#include "bit/bit.h"
#include "bit/item/item.h"
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
        Bit_node tmp = cur;
        int res = 0;        

        do { //navigo l'albero
                cur = tmp;
                Item cur_it  = bit_item(tmp);
                
                if ((res = item_compare(cur_it, item)) <= 0) {
                        tmp = bit_right(cur);
                } else {
                        tmp = bit_left(cur);
                }
                
        }while (tmp != NULL);

        Bit_node new = bit_new(item);
        bit_setParent(new, cur);

        if (res <= 0) { //inserisco
                bit_setRight(cur, new);
        } else {
                bit_setLeft(cur, new);
        }
};

int bist_delete(Bit_node *r, Key k);

Bit_node bist_new(Item item) {
        Bit_node new = bit_new(item);
        return new;
};
