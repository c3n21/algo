#ifndef BLIST_H
#define BLIST_H

typedef struct s_blist * BList;

typedef struct s_item * Item;

struct s_item {
        int el;
        char fmt [3];
};

BList BList_new();

BList BList_add(BList l, Item item);

void BList_append(BList l, Item item);

void BList_remove(BList l, int index, Item item);

void BList_print(BList l);

#endif
