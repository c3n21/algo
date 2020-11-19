#include "bist.h"

struct s_key {
        int n;
};

Item  bist_min( Bit_node p );
Item  bist_max( Bit_node p );

/*stampa  in  ordine  inverso:*/
void  bist_orderprint( Bit_node p );

/*stampa  in  ordine  inverso:*/
void  bist_invorderprint( Bit_node p );
Item  bist_search ( Bit_node r, Key k );
void  bist_insert( Bit_node *q, Item  item );
int  bist_delete( Bit_node *r, Key k );
