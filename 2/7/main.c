#include <stdio.h>
#include <malloc.h>

int main(int argc, char * args[]) {
        int n = 0;

        scanf("%d", &n);
        n++;

        int * seq = (int *) malloc(sizeof(int) * n);
        int m = 0;

        for (int i = 0; i < n; i++) {
                scanf("%d", &seq[i]);

                if (seq[i] != i) {
                        m = i;
                }
        }

        printf("Il valore mancante è %d", m);
        return 0;
}
