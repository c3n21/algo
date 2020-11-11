/*
 * OVERVIEW
 */

#ifndef SET_H
#define SET_H

#include "list.h"

typedef struct s_set {
        List * elements;
        List * last;
        unsigned int size;
} Set;

/**
 * void set_add(const Set * const set, int n);
 *
 * [MODIFIES]
 *      set->elements
 *      set->size
 * [EFFECT]
 *      adds a new element to the Set if it doesn't exist otherwise it does nothing
 *      if the elements array is full it will allocated more space
 */
void set_add(Set * set, int n);

/**
 * void set_delete(const Set * const set, int n);
 *
 * [MODIFIES]
 *      set->elements
 *      set->size
 * [EFFECT]
 *      deletes all elements and sets set->size to 0
 */
void set_clear(Set * set);

/**
 * void set_delete(const Set * const set, int n);
 *
 * [MODIFIES]
 *      set
 * [EFFECT]
 *      deletes if n matches to an element
 *      otherwise it does nothing
 */
void set_delete(Set * const set, int n);

/**
 * Set * set_new();
 *
 * [EFFECT]
 *      returns a new Set or NULL if there is no enough memory
 */
Set * set_new();

/**
 * int set_search(const Set * const set, int n);
 *
 * [EFFECT]
 *      return List * if found, NULL otherwise
 */
List * set_search(const Set * const set, int n);

/**
 * [MODIFIES]
 *      STDOUT
 * [EFFECT]
 *      prints the set
 */
void set_print(Set * l);
#endif
