#ifndef KEY_H
#define KEY_H

#define KEY_TYPE int

typedef struct s_key * Key;

Key key_new(void *);
void key_print(Key);
void key_delete(Key);
int key_compare(Key, Key);
void * key_value(Key);

#endif
