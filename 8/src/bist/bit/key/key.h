#ifndef KEY_H
#define KEY_H

#define KEY_TYPE void

typedef struct s_key * Key;

Key key_new(KEY_TYPE * e);
void key_print(Key key);

#endif
