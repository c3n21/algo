#include <stdio.h>

struct node {   
        int info;   
        struct node *next;
};

typedef struct node * Node;//2

void list_print(Node l) {
        if (l == NULL) {
                return;
        }
        printf("%d ", l->info);        
        list_print(l->next);
}
