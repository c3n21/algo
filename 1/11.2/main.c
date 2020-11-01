#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * args[] ) {

        int n = atoi( args[1] );
        
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                        if((i+j)% 2 == 1) {
                                printf("+");  
                        } else {
                                printf("o");  
                        }
                }
                printf("\n");
        }

        return 0;
}
