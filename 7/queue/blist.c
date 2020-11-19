#include "blist.h"
#include "queue.h"
#include <malloc.h>
#include <stdio.h>

struct s_blist {
        BList next;
        BList prev;
        int index;
        Item item;
};

Item makeItem(int n) {
        Item item = (Item) malloc(sizeof(Item));
        
        (item)->el = n;
        (item)->fmt[0] = '%';
        (item)->fmt[1] = 'd';
        (item)->fmt[2] = '\0';

        return item;
}

BList BList_new(Item item) {
        BList * new   = (BList *) malloc(sizeof(BList));
        (*new)        = (struct s_blist *) malloc(sizeof(struct s_blist));
        (*new)->next  = NULL;
        (*new)->prev  = NULL;
        (*new)->index = 0;
        (*new)->item  = item;

        return *new;
};

/*Add in the front*/
BList BList_add(BList l, Item item) {
        BList new = BList_new(item);
        (l)->prev = new;
        new->next = l;
        return new;
};

void BList_append(BList l, Item item) {
        BList current = (l);
        for (; current != NULL && current->next != NULL; 
                        current = current->next);
        BList new = BList_new(item);
        current->next = new;
};

void BList_remove(BList l, int index, Item item) {
        BList current = (l);

        for (int i = 0; 
                        i < index && current != NULL; 
                        i++, current = current->next);
        (l)->prev->next = (l)->next;
        (l)->next->prev = (l)->prev;
        free((l)->item);
        free((l));
};

void BList_print(BList l) {
        BList current = (l);
        for (; current != NULL && current->next != NULL; 
                        current = current->next) {
                printf("BList: index = %d ", l->index);
                printItem(l->item);
        }
};
