#include "bist.h"
#include "bit/bit.h"
#include "bit/item/item.h"
#include "bit/key/key.h"
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

void bist_insert(Bit_node *r, Item item) {
	Bit_node parent, q = *r, new = bist_new(item);
	Key k = item_key(item);

	/* se l’albero e’ vuoto: */
	if (q == NULL) {
		*r = new;
		return;
	}
	/* se la chiave c’e’ gia’, non inserisco niente: */
	if (bist_searchparent(*r, k, &parent, &q) == 0) {
		printf("c ’e ’ gia ’Â \n");
		return;
	}
	/* altrimenti inserisco il nuovo nodo come figlio di parent: */
	if (key_compare(k, item_key(bit_item(parent))) < 0)
                bit_setLeft(parent, new);
	else
		bit_setRight(parent, new);
}

int bist_delete(Bit_node *r, Key k) {
        Bit_node del, del_parent, sub = NULL;

        /* non ci sono nodi con chiave k, non faccio niente! */
        if (bist_searchparent(*r, k, &del_parent, &del) == 0) return 0;

        /* cerco il nodo sub che deve sostituire del */
        /*cerco sub, il massimo del sottoalbero di sinistra di del */
        Bit_node sub_parent = del;
        sub = bit_left(del);
        if (sub == NULL) { //non ha un sottoalbero di sinistra
                //mi limito a sostituirlo con il primo figlio di destra
                sub = bit_right(del);
        } else {
                /* ho un sottoalbero di sinistra, perciò vado a cercare il valore più grande
                 * in questo sottoalbero
                 */
                while (bit_right(sub)) {
                        sub_parent = sub;
                        sub = bit_right(sub);
                }

                /*
                 * assegno il sottoalbero destro di del a sub
                 */

                bit_setRight(sub, bit_right(del));
        }
        /* sostituisco x con s. Se x e’ la radice, diventa la nuova radice */
        if (del == *r) *r = sub; // x e’ la radice
        else if (bit_left(del_parent) == del) bit_setLeft(del_parent, sub);// x e’ figlio sinistro 
        else bit_setRight(del_parent, sub);// x è figlio destro
                
        bit_destroy(del);

        return 0;
}

Bit_node bist_new(Item item) {
        Bit_node new = bit_new(item);
        return new;
};

Item bist_search(Bit_node p, Key k) {
    if (!p)
        return NULL;
    Item item = bit_item(p);
    int res = key_compare(k, item_key(item));

    if (res == 0)
        return item;

    if (res < 0)
        return bist_search(bit_left(p), k);

    return bist_search(bit_right(p), k);
}

Item bist_search_it(Bit_node p, Key k) {
    int res;
    while (p && (res = key_compare(k, item_key(bit_item(p)))) != 0)
        p = res < 0 ? bit_left(p) : bit_right(p);

    return bit_item(p);
}

/**
 * Search parent node for Key k
 *
 * @param Bit_node root
 *
 * @param Key k
 *      key to look up for in the bist
 *
 * @param Bit_node *parent 
 *      stores the parent of p
 *
 * @param Bit_node *found
 *      contains the node corresponding with @param k
 *
 * @return int 1 if found, 0 if not found
 */

int bist_searchparent(Bit_node root, Key k, Bit_node *parent, Bit_node *found) {
    if (!root)
        return 0;

    int res;
    *parent = NULL;
    *found = root;

    while (*found && (res = key_compare(k, item_key(bit_item(*found)))) != 0) {
        *parent = *found;
        *found = res < 0 ? bit_left(*found) : bit_right(*found);
    }
    if (*found == NULL) /* non ci sono nodi con chiave k */
        return 0;
    return 1;
}
