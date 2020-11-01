#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main( int argc, char * args[] ) {

    int i    = atoi( args[1] );

    int cols = i + 2;
    printf("i = %d; cols = %d;\n", i, cols);
    char * s = ( char *) malloc( ( cols + 1 ) * sizeof( char ));


    memset( s, '-', ( cols - 1) );
    *(s + cols - 1) = '*';
    *( s + cols ) = '\0';

    for (; i > 3; i-- && cols--) {
        printf("%s\n", s);
        *(s + cols - 1) = '-'; 
        *(s + cols - 2) = '*';
    }

    //terzultima riga
    *(s + cols )    = '-'; 
    *(s + cols - 1) = '*';
    *s              = '*';
    printf("%s\n", s);
    cols--;

    //penultima riga
    *(s + cols )    = '-'; 
    *(s + cols - 1) = '*';
    *s              = '-';
    *(s + 1)        = '*';
    printf("%s\n", s);
    cols--;

    //ultima riga
    *(s + cols )    = '-'; 
    *(s + cols - 1) = '*';
    *(s + 1)        = '-';
    printf("%s\n", s);
    return 0;
}
