#include <stdio.h>
#include <ctype.h>

int main(int argc, char * args[]) {
        int c, f[10] = {0};
        int k = 0;

        c = getchar();
        while ( c != '.' ) {
                if ( isdigit( c ) ) {
                        f[ c - '0' ]++;
                        k++;
                }
                c = getchar();
        }

        for (int i = 0; i < 10; i++) {
                if (f[i] >= 2) { printf("%d", i);
                }
        }
        return 0;
}
