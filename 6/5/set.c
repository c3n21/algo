#include <malloc.h>
#include "set.h"
#include "list.h"
#include "debug.h"


void set_add(Set * const set, int n) {
        if(set_search(set, n) == NULL) {
                debug_print("[SET::set_add] ELEMENT NOT FOUND... ADDING\n");
                
                if (set->last == NULL) {
                        debug_print("[SET::set_add] INIT\n");
                        set->elements = list_new(n);
                        set->last = set->elements;
                } else {
                        debug_print("[SET::set_add] APPENDING\n");
                        list_append(set->last, n);
                        set->last = set->last->next;
                }
                set->size++;
        }
}

void set_clear(Set *set) {
        list_clear(set->elements);
        set->size = 0;
        set->elements = NULL;
        set->last = NULL;
}

void set_delete(Set * const set, int n) {
        debug_print("[SET::set_delete] DELETING ELEMENT\n");
        set->last = list_delete(set->elements, n);
        set->size--;
}

Set * set_new() {
        Set * set = (Set *) malloc(sizeof(Set));
        
        if (set != NULL) {
                set->elements = NULL;
                set->last = NULL;
        }

        return set;
}

List * set_search(const Set * const set, int n) {
        List * res = NULL;

        if (set->elements != NULL) {
                res = list_search(set->elements, n);
        }

        return res;
}

void set_print(Set * l) {
        if (l != NULL) {
                list_print(l->elements);
        }
}
