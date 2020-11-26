#include "bist.h"
#include "bit/bit.h"
#include "bit/item/item.h"
#include "bit/key/key.h"
#include "../debug/debug.h"
#include <stdio.h>
#include <stdlib.h>

struct s_bist {
        unsigned long inc;
        Bit_node root;
};

Bist bist_new(Item item) {
        Bist new = (Bist) malloc(sizeof(struct s_bist));
        new->inc = 0;
        new->root = bit_new(item);

        return new;
}

Bit_node bist_root(Bist root) {
        if (root != NULL) {
                return root->root;
        }

        return NULL;
}

Item bist_min(Bist p);
Item bist_max(Bist p);

/*stampa  in  ordine  inverso:*/
void bist_orderprint(Bist p);

/*stampa  in  ordine  inverso:*/
void bist_invorderprint(Bist p);

/**
 * 
 * @param root
 * @param item
 *
 * @return 
 *
 */
int bist_insert(Bist root, Item item) {
        if (root != NULL) {
                Bit_node cur_parent = NULL;
                debug_print("[bist_insert] root = %p\n", root->root);
                debug_print("[bist_insert] cur_parent = %p\n", cur_parent);

                int side = bist_searchparent(root, item, &cur_parent); 

                if (cur_parent != NULL) {
                        Bit_node new_node = bit_new(item);

                        debug_print("[bist_insert] cur_parent = %p, left = %p, right = %p, side = %d\n",
                                        cur_parent, bit_left(cur_parent), bit_right(cur_parent), side);

                        if (side == 1){ //side == 1 is left child, side == 0 is right side
                                debug_print("[bist_insert] setting new_node in left side\n");
                                bit_setLeft(cur_parent, new_node);
                        } else if (side == 0) {
                                debug_print("[bist_insert] setting new_node in right side\n");
                                bit_setRight(cur_parent, new_node);
                        } else {
                                debug_print("[bist_insert] ERROR: no valid value on insert, side = %d\n", side);
                                exit(1);
                        }

                        return 1;
                } else {
                        debug_print("[bist_insert] cur_parent is still NULL after bist_searchparent\n", cur_parent);
                        exit(1);
                }
        }
        debug_print("[bist_insert] Couldn't insert element\n");
        return -1;
}



//int bist_delete(Bist r, Key k) {
//        Bist del, del_parent, sub = NULL;
//
//        /* non ci sono nodi con chiave k, non faccio niente! */
//        if (bist_searchparent(*r, k, &del_parent, &del) == 0) return 0;
//
//        /* cerco il nodo sub che deve sostituire del */
//        /*cerco sub, il massimo del sottoalbero di sinistra di del */
//        Bist sub_parent = del;
//        sub = bit_left(del);
//        if (sub == NULL) { //non ha un sottoalbero di sinistra
//                //mi limito a sostituirlo con il primo figlio di destra
//                sub = bit_right(del);
//        } else {
//                /* ho un sottoalbero di sinistra, perciò vado a cercare il valore più grande
//                 * in questo sottoalbero
//                 */
//                while (bit_right(sub)) {
//                        sub_parent = sub;
//                        sub = bit_right(sub);
//                }
//
//                /*
//                 * assegno il sottoalbero destro di del a sub
//                 */
//
//                bit_setRight(sub, bit_right(del));
//        }
//        /* sostituisco x con s. Se x e’ la radice, diventa la nuova radice */
//        if (del == *r) *r = sub; // x e’ la radice
//        else if (bit_left(del_parent) == del) bit_setLeft(del_parent, sub);// x e’ figlio sinistro 
//        else bit_setRight(del_parent, sub);// x è figlio destro
//                
//        bit_destroy(del);
//
//        return 0;
//}

//Bist bist_new(Item item) {
//        Bist new = (Bist) malloc(sizeof(struct s_bist));
//
//        Bist new_root = bit_new(item);
//        return new;
//};
//
//Item bist_search(Bist p, Key k) {
//    if (!p)
//        return NULL;
//    Item item = bit_item(p);
//    int res = key_compare(k, item_key(item));
//
//    if (res == 0)
//        return item;
//
//    if (res < 0)
//        return bist_search(bit_left(p), k);
//
//    return bist_search(bit_right(p), k);
//}
//
//
//Item bist_search_it(Bist p, Key k) {
//    int res;
//    while (p && (res = key_compare(k, item_key(bit_item(p)))) != 0)
//        p = res < 0 ? bit_left(p) : bit_right(p);
//
//    return bit_item(p);
//}
//
/**
 * Stores parent for the new child with Item item, and returns 1 if it will be left child or right child
 *
 * @param Bist root
 *
 * @param Key k
 *      key to look up for in the bist
 *
 * @param Bist *parent 
 *      stores the parent of p
 *
 * @param Bist *found
 *      contains the node corresponding with @param k
 *
 * @return 1 if left child, 0 it's right child
 */

int bist_searchparent(Bist root, Item item, Bit_node * r_parent) {
        if (root != NULL) {
                *r_parent = root->root;
                Bit_node cur_parent = NULL;
                int cmp = 0;
                for (Bit_node cur_node = root->root; cur_node != NULL;) {
                        Item cur_item = bit_item(cur_node);
                        cur_parent = cur_node;
                        

                        cmp = item_compare(item, cur_item);

                        if (cmp >= 0) {
                                cur_node = bit_right(cur_node);
                                cmp = 0;
                        } else if (cmp == -1) {
                                cur_node = bit_left(cur_node);
                                cmp = 1;
                        } else {
                                debug_print("[bist_searchparent] ERROR: Not valid value in Items comparation, cmp = %d\n", cmp);
                                exit(1);
                        }
                }

                if (cur_parent != NULL) {
                        *r_parent = cur_parent;
                        return cmp;
                } else {
                        debug_print("[bist_searchparent] ERROR: no adequate parent found\n");
                        exit(1);
                }
        }
        debug_print("[bist_searchparent] ERROR: root is NULL\n");
        exit(1);
}
