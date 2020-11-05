#include <stdio.h>
#include <stdlib.h>

struct node {   
        int info;   
        struct node *next;
};

typedef struct node * Node;//2

Node list_insert( int n, Node * l ){
        Node new = (Node ) malloc( sizeof(Node) ); //[1]
        new -> info = n;
        new -> next = *l;
        *l = new;

        return new; 
}

void list_delete( int n, Node *l){ //modificato struct node *
        struct node *curr, *prev;
        for ( curr = *l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
                if (curr -> info == n ) break;
        }
        if (curr == NULL) {//no element found
                printf("curr == NULL %d\n", n);
                return;
        }

        if (prev == NULL) {//l'elemento da eliminare è il primo
                printf("prev == NULL %d\n", n);
                *l = (*l) -> next; //modificato qui
        } else {//l'elemento da eliminare è tra il secondo ed ultimo elemento
                printf("else %d\n", n);
                prev -> next = curr -> next;
        }
        free(curr);
}

void list_print(Node * l) {
        if (l == NULL) {
                return;
        }

        printf("%p %d\n",*l, (*l)->info);        
        
        if ((*l)->next != NULL) {
                list_print(&(*l)->next);
        }
}

int main() {
        struct node *first = NULL; //
        Node head = (Node ) malloc( sizeof(Node) ); //[1]

        int n = 0;
        head->info = -1;
        head->next = NULL;
        list_insert(n, &head);
        //list_delete(0 , head );
        list_delete(0 , &head );
        list_print(&head);
        return 0;
}

/*
 * [1] Quando non viene trovato il nodo con l'elemento cercato
 * [2] Quando il nodo da eliminare è anche il primo nodo (l)
 * [3] Quando il nodo da eliminare si trova tra il secondo e l'ultimo nodo compreso
 * [5] Quando devi cancellare il primo elemento
 */
