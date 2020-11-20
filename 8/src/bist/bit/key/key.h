#ifndef KEY_H
#define KEY_H

typedef struct s_key * Key;

Key key_new(void * e);
void key_print(Key key);
void key_delete(Key key);

#endif
