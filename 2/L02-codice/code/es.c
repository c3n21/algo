#include <stdio.h>

#define LENGTH 100

int main( void) {

    int a[LENGTH], i, lun;

    for( i = 0; i < LENGTH; i++ ) {
        scanf( "%d", &a[i] );
        if ( a[i] == 0 )
            break;
    }

    lun = i;

    for( i = lun -1; i > 0; i-- )
        printf( "%d ", a[i] );

    printf( "%d\n", a[0] );
    return 0;
}

/*
 * Permette all'utente di inserire in un array al massimo 100 numeri per poi stamparli a ritroso
 *
