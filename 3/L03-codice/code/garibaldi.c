#include <stdio.h>

char garibaldi( char a, char b ){
    if ( b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u' )
        return a;
    else return b;
}

int main() {
    char c, vocale;

    vocale = getchar();
    getchar();

    while ( ( c = getchar() ) != '.' )
        printf( "%c", garibaldi( vocale, c ) );

    printf( "\n" );
    return 0;
}
/*
 * [1] 
 * vocale = u
 * output = gurubuldu fu furutu, fu furutu un unu gumbu
 * [2] Se il carattere b è una vocale la sostuisce con il carattere a
 * [3] Il programma sostituisce con un carattere a scelta dato dall'utente tutte le vocali di una stringa con questo carattere
 *
 */
