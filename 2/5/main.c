#include <stdio.h>
#include <string.h>



void insert(int * array, int n, int size) {
        for (int i = 0; i < size-1 && n; i++) { //0 cannot be inserted

                printf("Sto ancora stampando i = %d\n", i);
                if (array[i] == 0) {
                        array[i] = n;
                        i = size;
                } else {
                        if (array[i] > n) {
                                int swap = array[i];
                                array[i] = n;
                                n        = swap;
                                //printf("offset = %ld\n", (array+size) - (array+i+2));
                                memmove(array+i+2, array+i+1, (array+size) - (array+i+2));
                                array[i+1] = swap;
                                i = size;
                        }
                }
        }
}

int main() {
        int array [100] = {0};
        for (int i = 0, n = -1; i < 100 && n; i++) {
                scanf("%d", &n);

                insert(array, n, 100);
        }

        for (int i = 0; i < 100; i++) {
                printf("i = %d, value = %d\n", i, array[i]);
        }
        return 0;
}
