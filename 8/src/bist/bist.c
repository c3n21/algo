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

/*
 * @param root
 * @param item
 * @param found
 *
 * @return 1 if found, else 0
 *
 */
int searchNode(Bit_node root, Item item, Bit_node found) {
        if (root == NULL) {
                return 0;
        }

        Item it = bit_item(root);

        int cmp = item_compare(item, it);

        if (cmp == 0) {
                found = root;
                return 1;
        }

        if (cmp == -1) { //item's value is less than it
                return searchNode(bit_left(root), item, found);
        }

        if (cmp == 1) { //item's value is less than it
                return searchNode(bit_right(root), item, found);
        }

        return 0;
}

Item bist_min(Bist p);
Item bist_max(Bist p);

/*stampa  in  ordine  inverso:*/
void bist_orderprint(Bist p);

/*stampa  in  ordine  inverso:*/
void bist_invorderprint(Bist p);

int bist_insert(Bist root, Item item) {
        if (root != NULL) {
                Bit_node cur_parent = NULL;
                int cmp = 0; 
                for (Bit_node cur_node = root->root; cur_node != NULL;) {
                        Item cur_item = bit_item(cur_node);
                        cur_parent = cur_node;

                        cmp = item_compare(item, cur_item);


                        if (cmp >= 0) {
                                cur_node = bit_right(cur_node);

                        } else if (cmp == -1) {
                                cur_node = bit_left(cur_node);
                        } else {
                                debug_print("[bist_insert] Error detected in Items comparation, cmp = %d\n", cmp);
                                return 0;
                        }
                }


                if (cur_parent != NULL) {
                        Bit_node new = bit_new(item);

                        debug_print("[bist_insert] cur_parent = %p, left = %p, right = %p, cmp = %d\n", cur_parent, bit_left(cur_parent), bit_right(cur_parent), cmp);

                        if (cmp >= 0) {
                                bit_setRight(cur_parent, new);

                        } else if (cmp == -1) {
                                bit_setLeft(cur_parent, new);
                        } else {
                                debug_print("[bist_insert] Error detected in Item insertion, cmp = %d\n", cmp);
                                return 0;
                        }
                } else {
                        return 0;
                }

                return 1;
        }
        
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
//
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
///**
// * Search parent node for Key k
// *
// * @param Bist root
// *
// * @param Key k
// *      key to look up for in the bist
// *
// * @param Bist *parent 
// *      stores the parent of p
// *
// * @param Bist *found
// *      contains the node corresponding with @param k
// *
// * @return int 1 if found, 0 if not found
// */
//
//int bist_searchparent(Bist root, Key k, Bist *parent, Bist *found) {
//    if (!root)
//        return 0;
//
//    int res;
//    *parent = NULL;
//    *found = root;
//
//    while (*found && (res = key_compare(k, item_key(bit_item(*found)))) != 0) {
//        *parent = *found;
//        *found = res < 0 ? bit_left(*found) : bit_right(*found);
//    }
//    if (*found == NULL) /* non ci sono nodi con chiave k */
//        return 0;
//    return 1;
//}
