#include <stdio.h>
#include <string.h>

int main( int argc, char * args[] ) {

        int l = strlen(args[1]);
        int c = 0;

        for ( int i = 0; i < l; i++ ) {
                if ( args[1][i] == '(' ) {
                        c++;
                }

                if ( args[1][i] == ')' ) {
                        c--;
                }
        }

        return c == 0;
}
