#include <stdio.h>

int main(int argc, char * args[]) {
        int n = 0;
        char simbolo = '+';

        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
                if(i%2) {
                        simbolo = '+';
                } else {
                        simbolo = 'o';
                }

                for(int j = 0; j < n; j++) {
                        printf("%c", simbolo);
                }
                printf("\n");
        }

        return 0;
}
