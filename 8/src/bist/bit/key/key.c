#include "key.h"
#include <stdio.h>
#include <stdlib.h>

struct s_key {
        KEY_TYPE val;
};

Key key_new(void * e) {
        Key key = (Key) malloc(sizeof(struct s_key));
        key->val = *(KEY_TYPE *) e;
        return key;
};

void key_print(Key key) {
        if (key != NULL) {
                printf("%d", key->val);
        }
};

void key_delete(Key key) {
        free(key);
}

int key_compare(Key key1, Key key2) {
        if (key1 == key2) {//even if both are null
                return 0;
        }

        if (key1 == NULL || key1->val < key2->val) {
                return -1;
        }
        
        return 1;
}

void * key_value(Key key) {
        if (key != NULL) {
                return &key->val;
        }
        return NULL;
}
