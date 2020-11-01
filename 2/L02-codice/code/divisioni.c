#include <stdio.h>
#define N 10

int main( void) {
    int b, n, i = 0;
    int c[N] = {0}; 
    
    //[4]
    printf("Inserisci un numero da convertire ");
    scanf( "%d %d", &n, &b );
    
    do c[i++] = n % b;
        while ( ( n /= b ) > 0 );

    //[4]
    printf("Il numero convertito è: ");

    while ( i > 0 )
        printf( "%d", c[--i] ); 
     
    printf( "\n" ); 
    
    return 0;
}

/*
 * [1] n -> numero da convertire
 *     b -> base d'arrivo del numero da convertire
 * [2] cifre
 * [3] conversione in base b
 * [5] Il programma converte un numero n in una qualunque base b che deve essere minore di 10
 * [6] È la terza cifra più significativa del numero n
 */
