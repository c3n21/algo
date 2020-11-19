#include "bit.h"

Bit_node  bit_new( Item );
void  bit_destroy( Bit_node  );
Item  bit_item( Bit_node  );
Bit_node  bit_left( Bit_node  );
Bit_node  bit_right( Bit_node  );
void  bit_printnode( Bit_node  );
void  bit_preorder( Bit_node  );
void  bit_inorder( Bit_node  );
void  bit_postorder( Bit_node  );

void  bit_printassummary( Bit_node p, int  spaces  );
Bit_node  bit_arr2tree( Item *a, int size , int i );
