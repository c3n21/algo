#ifndef LIST_H
#define LIST_H

typedef struct s_list {
        struct s_list * next;
        int n;
} List;

/**
 * void list_append(List * prev, int n);
 *
 * [REQUIRES]
 *      prev MUST not be NULL
 * [MODIFIES]
 *      l
 * [EFFECT]
 *      adds a node as prev->next
 */
void list_append(List * prev, int n);

/**
 * void list_delete(const Set * const set, int n);
 *
 * [MODIFIES]
 *      l
 * [EFFECT]
 *      deletes all the nodes in the list
 */
void list_clear(List * l);

/**
 * void list_delete(const Set * const set, int n);
 *
 * [MODIFIES]
 *      l
 * [EFFECT]
 *      deletes the node if n matches l->n, and it should show the following behavious:
 *              if l's length is zero it will return null
 *              if l's length is >= 1 it will return the node behind the one it eliminates
 *      otherwise it returns NULL and does nothing
 */
List * list_delete(List * l, int n);

/**
 * List * list_new(int n);
 *
 * [EFFECT]
 *      return List if it is created, NULL otherwise
 */
List * list_new(int n);

/**
 * [MODIFIES]
 *      STDOUT
 * [EFFECT]
 *      prints the list
 */
void list_print(List * l);

/**
 * int list_search(const List * const l, int n);
 *
 * [EFFECT]
 *      return List * if found, NULL otherwise
 */
List * list_search(List * l, int n);

#endif
