#include "key.h"
#include <stdio.h>
#include <stdlib.h>

#undef KEY_TYPE
#define KEY_TYPE int

struct s_key {
        KEY_TYPE val;
};

Key key_new(void * e) {
        Key key = (Key) malloc(sizeof(struct s_key));
        key->val = *(KEY_TYPE *) e;
        return key;
};

void key_print(Key key) {
        printf("%d", key->val);
};

void key_delete(Key key) {
        free(key);
}