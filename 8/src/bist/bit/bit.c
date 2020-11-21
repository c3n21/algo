#include "bit.h"
#include "item/item.h"
#include <stdio.h>
#include <stdlib.h>

#define BIT_PARAGRAPH '*'
#define BIT_SPACES_OFFSET 4

struct s_bit_node {
        Item item;
        Bit_node left, right;
        Bit_node parent;
};

void insert(Bit_node root, Item item) {

        Bit_node cur = root; 
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
}
Bit_node bit_new(Item item) {
        Bit_node new = (Bit_node)malloc(sizeof(struct s_bit_node));
        new->item = item;
        new->left = NULL;
        new->right = NULL;
        new->parent = NULL;

        return new;
};

void bit_destroy(Bit_node bt) {
        if (bt != NULL) {
                bit_destroy(bt->left);
                bit_destroy(bt->right);
                item_delete(bt->item);
                free(bt);
        }
};

Item bit_item(Bit_node bt) { return bt->item; };

Bit_node bit_left(Bit_node bt) { return bt->left; };

Bit_node bit_right(Bit_node bt) { return bt->right; };

void bit_setLeft(Bit_node bt, Bit_node left) {
        bt->left = left;
}

void bit_setRight(Bit_node bt, Bit_node right) {
        bt->right = right;
}

void bit_setParent(Bit_node bt, Bit_node parent) {
        bt->parent = parent;
}

void bit_printnode(Bit_node bt) {
        printf("Node = %p, Item = ", bt);
        item_print(bt->item);
        printf("\n");
};

void bit_preorder(Bit_node);
void bit_inorder(Bit_node);
void bit_postorder(Bit_node);

void bit_printassummary(Bit_node p, int spaces) {
        if (p != NULL) {
                for (int i = 0; i < spaces; i++) {
                        printf(" ");
                }
                printf("%c", BIT_PARAGRAPH);
                item_print(p->item);
                printf("\n");
                bit_printassummary(p->right, spaces + BIT_SPACES_OFFSET);
                bit_printassummary(p->left, spaces + BIT_SPACES_OFFSET);
        }
};

Bit_node bit_arr2tree(Item *a, int size, int i) {
        Bit_node root = NULL;

        for (int i = 0; i < size; i++) {
                Item item = item_new(&i);

                if (root == NULL) {
                        root = bit_new(item);
                } else {
                        insert(root, item);
                }
        }

        return root;
};
