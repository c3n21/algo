#include <stdio.h>

#define ARRAY_SIZE 1024

int ARR[ARRAY_SIZE] = {0};

void merge(int a[], int i, int m, int f);
void mergesort(int a[], int sx, int dx);
void selectionsort(int a[], int n);
void scambia(int a[], int i, int j);
void stampa(int a[], int lung);

int main() {
        int array[ARRAY_SIZE] = {0};
        for (int i = 0; i < ARRAY_SIZE; i++) {
                scanf("%d", &array[i]);
        
        }

        stampa(array, ARRAY_SIZE);

        printf("Riordinando...\n");
        //selectionsort(array, ARRAY_SIZE);
        mergesort(array, 0, ARRAY_SIZE);
        stampa(array, ARRAY_SIZE);

        return 0;
}

/**
 * void merge(int a[]);
 *
 *  [REQUIRES]
 *      a[] must be a valid array n-lengthed array
 *  [EFFECTS]
 *      sorts elements in a[] using selection sort
 */
void merge(int a[], int i, int m, int f) {
        int i1 = i, i2 = m, k = 0;
        int x[f - i];

        for (; i1 < m && i2 < f; k++) {
                if (a[i1] <= a[i2]) {
                        x[k] = a[i1];
                        i1++;
                } else {
                        x[k] = a[i2];
                        i2++;
                }
        }

        if (i1 < m) {
                for (; i1 < m; i1++, k++) {
                        x[k] = a[i1];
                }
        } else {
                for (; i2 < f; i2++, k++) {
                        x[k] = a[i2];
                }
        }

        for (k = 0; k < (f - i); k++) {
                a[i + k] = x[k];
        }
}

/**
 * void mergesort(int a[], int sx, int dx);
 *
 *  [REQUIRES]
 *      a[] must be a valid array n-lengthed array
 *      sx must be a valid a[sx] element
 *      dx same above
 *  [EFFECTS]
 *      sorts elements in a[] using selection sort
 */
void mergesort(int a[], int sx, int dx) {
        if (dx - sx > 1) { //at least 3 elements
                int offset = (dx+sx)/2;
                printf("dx = %d, sx = %d, offset = %d\n", dx, sx, offset);
                mergesort(a, sx, offset);
                mergesort(a, offset, dx);
                merge(a, sx, offset, dx);
        }
}

/**
 * void scambia(int a[], int i, int j);
 */
void scambia(int a[], int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
}

/**
 * void selectionsort(int a[], int n) {
 *  [REQUIRES]
 *      a[] must be a valid array n-lengthed array
 *  [EFFECTS]
 *      sorts elements in a[] using selection sort
 */
void selectionsort(int a[], int n) {
        if (n > 1) {
                int i = 0;
                int max = 0;

                for (; i < n; i++) {
                        if (a[max] < a[i]) {
                                max = i;
                        }        
                }

                scambia(a, max, n-1);
                selectionsort(a, n-1);
        }
}
/**
 * void stampa(int a[], int lung);
 */
void stampa(int a[], int lung) {
        for (int i = 0; i < lung; i++) {
                printf("a[%d] %d\n",i, a[i]);
        }
}
