#include <malloc.h>

struct node {   
        int info;   
        struct node *next;
};

typedef struct node * Node;//2

Node list_insert( int n, Node * l ){
        Node new = (Node ) malloc( sizeof(Node) ); //[1]
        new -> info = n;
        new -> next = *l;
        l = &new;

        return new; 
}

Node list_search( int n, Node * l ){
        for (; l != NULL && (*l)->info != n; l = &(*l)->next); //[5]
//        while ( l != NULL && l -> info != n )
//                l = l -> next;
        return *l;
}

Node list_search_rec(int n, Node l) { //[7]
        if (l == NULL) {
                return NULL;
        }

        if (l->info == n) {
                return l;
        }

        return list_search_rec(n, l->next);

}

/*
 * [3] Crea un nodo senza il nodo successivo 
 * [4] Ritorna il nodo l passato come argomento
 * [6] Restituisce la prima occorrenza del nodo che contiene l'info cercata
 */
