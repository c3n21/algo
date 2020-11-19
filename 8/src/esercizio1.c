#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main(int argc, char * args[]) {
        srand(time(NULL));
        int array [ARRAY_SIZE];

        for (int i = 0; i < ARRAY_SIZE; i++) {
                array[i] = rand();
                printf("%d\n", array[i]);
        }

        return 0;
}
