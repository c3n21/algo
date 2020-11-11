#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next; int val; };

typedef struct node *Node;

Node newNode( int val, Node p );
int f1 ( Node p );
Node f2 ( Node p );
Node f3 ( Node p, Node q );
void list_print(Node l);
void list_printInv(Node l);
int * listToArray(Node l, int size);
int listSize(Node list);
void list_destroy(Node l);
void list_destroy_iter(Node l);

int main(){ Node x = newNode( 1, NULL ); Node head = newNode( 2, x );
        head = newNode(3, head);
        
        list_print(head);
        printf("Fai schifo\n");
        list_printInv(head);
        int size = listSize(head);
        int * array = listToArray(head, size);

        for (int i = 0; i < size; i++) {
                printf("%d ", array[i]);
        }

        printf("%c\n", 8);

//        list_destroy(head);
        list_destroy_iter(head);
}

void list_print(Node l) { //3.1
        if (l == NULL) {
                return;
        }

        printf("%p %d\n",l, l->val);        
        
        if (l->next != NULL) {
                list_print(l->next);
        }
}

void list_printInv(Node l) { //3.2
        if (l == NULL) {
                return;
        }

        if (l->next == NULL) {
                printf("p: %p, val: %d\n", l, l->val);
                return;
        }

        list_printInv(l->next);
        printf("p: %p, val: %d\n", l, l->val);
}

int listSize(Node list) {
        int i = 0;
        for (; list != NULL; i++, list = list->next);

        return i;
}

int * listToArray(Node l, int size) {
        int * array = (int *) malloc(sizeof(int) * size);
        
        for (int i = 0; l != NULL; i++, l = l->next) {
                array[i] = l->val;
        };

        return array;
}

Node newNode( int val, Node p ){
	Node new = malloc( sizeof (struct node));
	new -> val = val;
	new -> next = p;
	return new;
}

int f1 ( Node p ){
	getchar();
	if ( p -> next == NULL )
		return 1;
	else
		if ( p -> val < p -> next -> val )
			return 0;
		else
			return f1( p -> next );
}

Node f2 ( Node p ){
	getchar();
	if (  p -> next == NULL ) 
		return p;
	else 
		return f3( p -> next, p );
}


Node f3 ( Node p, Node q ){
	Node temp;
	if ( p -> val < q -> val )
		temp = p;
	else
		temp = q;
	if ( p -> next == NULL )
		return temp;
	else 
		return f3( p -> next, temp );
	
}

void list_destroy(Node l) {
        if (l == NULL) {
                return;
        }

        list_destroy(l->next);
        free(l);
}

void list_destroy_iter(Node l) {
        for (Node next = l->next; l != NULL && next->next != NULL; l = next, next = next->next) {
                free(l);
        }
}//3.5 è void perché non deve ritornare nulla dato che la lista viene cancellata

struct node * olist_insert(int n, struct node *l) {
        struct node * prev = NULL;
        struct node * new = l;

        for (; l != NULL && l->val < n; prev = l, l = l->next);
        
        if (prev != NULL) {
                new = (struct node *) malloc(sizeof(struct node));
                new->val = n;
                new->next = prev->next;
                prev->next = new;
        }

        return new;
}

struct node * olist_search(int n, struct node *l) {
        /**
         * Quando val > n
         */
        Node found = NULL;

        for (; l != NULL && l->val < n; l = l->next);

        if (l->val == n) {
                found = l;
        }

        return found;
}

/**
 * [Scheda due]
 * [1] 1
 * [2] d
 * [3] se la lista è ordinata in ordine strettamente crescente
 * [4] l'ultimo nodo ovvero quello con val = 1
 * [5] restituisce un puntatore all'ultimo nodo della lista
 */
