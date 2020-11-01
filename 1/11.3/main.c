#include <stdio.h>

int main( int argc, char * args[] ) {

        int n = atoi( args[1] );
        
        for(int i = 0; i < n; i++) {
                char c = 'o';

                for(int j = 0; j < n; j++) {
                        if(j > i) {
                                c = '+';
                        }

                        if(i == j) { //diagonale
                                c = '|';
                        }

                        printf("%c", c);
                }
                printf("\n");
        }

        return 0;
}
