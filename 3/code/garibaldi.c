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
