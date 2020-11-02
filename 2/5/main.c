#include <stdio.h>
#include <string.h>

int main() {
        int array [100] = {0};
        int n = 0;
        scanf("%d", &n);

        for (int i = 0; i < 100 && n; i++) {
                int j = i;
                for (; j-1 >= 0 && array[j-1] > n; j--) {
                        array[j] = array[j-1];
                }
                array[j] = n;
                scanf("%d", &n);
        }

        for (int i = 0; i < 100; i++) {
                printf("i = %d, value = %d\n", i, array[i]);
        }
        return 0;
}
