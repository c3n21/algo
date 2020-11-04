#include <stdio.h>

#define MAX 100

int main(int argc, char * args[]) {
        int r = 0, c = 0;
        char m[MAX][MAX] = {{0}};

        scanf(" %d %d", &r, &c);
        printf("r = %d, c = %d\n", r,c );
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        scanf("\n%c", &m[i][j]);

                }
        }

        for (int j = 0; j < c; j++) {
                for (int i = 1; i < r; i++) {
                        if (m[i][j] == '*') {
                                m[i][j] = m[i-1][j];
                                m[i-1][j] = '*';
                        }
                }
        }

        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        printf("%c ", m[i][j]);
                }
                printf("\n");
        }

        return 0;
}
