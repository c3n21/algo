#include "list.h"
#include <malloc.h>
#include <stdio.h>
#include "debug.h"

void list_append(List * prev, int n) {
        prev->next = list_new(n);
}

void list_clear(List * l) {
        for (List * prev = NULL; l != NULL; prev = l, l = l->next){
                free(prev);
        }
}

List * list_delete(List * l, int n) {
        List * current = l;
        List * prev = NULL;

        for (; current != NULL && current->n != n; prev = current, current = current->next);

        if (prev != NULL) { //it's at least the second
                if (current != NULL) {
                        prev->next = current->next;
                        free(current);
                        l = prev;
                }
        }
        return l;
}

List * list_new(int n) {
        List * l = (List *) malloc(sizeof(List));
        
        if (l != NULL) {
                l->n = n;
                l->next = NULL;
        }

        return l;
}

List * list_search(List * l, int n) {
        for (; l != NULL && l->n != n; l = l->next);

        return l;
}

void list_print(List * l) {
        for (; l != NULL; l = l->next) {
                printf("next = %p, n = %d\n", l->next, l->n);
        }
}
