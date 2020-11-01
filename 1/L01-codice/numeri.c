/*
 * [1] si aspetta una serie di numeri tranne 0, su cui termina
 * [2] 0
 * [3] la somma di tutti i numeri inseriti
 * [4] Sono memorizzati prima su una variabile intera, e dopo sommata alla variabile x
 * [5] Il programma legge da STDIN una serie di numeri diversi da 0, e poi li somma finché non gli viene passato 0 come cifra ed infine stampa la somma di tutti i numeri inseriti.
 */

#include <stdio.h>

int main( void ) {
        int n = 1, x = 0, i = 0;
        printf( "Inserisci una serie di numeri: " );

        do {
                scanf( "%d", &n );
                x = x + n;
        } while ( n != 0 && ++i);

        printf( "%d\n", i );
        printf( "%d\n", x/i );
        return 0;

}
