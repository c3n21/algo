#include <stdio.h>
#include <malloc.h>

int main(int argc, char * args[]) {
        int n = 0;

        scanf("%d", &n);

        int * bits = (int *) malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) {
                scanf("%d", &bits[i]);
        }

        for (int i = 0, j = n-1; i < n/2; i++) {
                if (bits[i] != 0) {
                        while (bits[j] == 1 && j-- > n/2){
                                
                        };
                        bits[i] = 0;
                        bits[j] = 1;
                }
        }

        for (int i = 0; i < n; i++) {
                printf("%d ", bits[i]);
        }
        return 0;
}
