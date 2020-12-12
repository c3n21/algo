#include <stdio.h>

#define OBJECTS 3
typedef struct s_types {
        int weight;
        int value;
}Object;

int fillBag(int * p, Object * objects, int index, int objects_n);

int main() {
        int p;
        Object objects[OBJECTS];

        scanf("%d", &p);

        for (int i = 0; i < OBJECTS && 
                        scanf("%d", &objects[i].weight) != EOF && 
                        scanf("%d", &objects[i].value) != EOF; i++) {
        }

        printf("Portata zaino = %d\n", p);
        for (int i = 0; i < OBJECTS; i++) {
                printf("objects[%d].weight = %d, value = %d\n", i, objects[i].weight, objects[i].value);
        }

        int buffer[p+1];
        for (int i = 0; i < p+1; i++) {
                buffer[i] = -1;
        }

        printf("Soluzione = %d\n", fillBag(buffer, objects, p, OBJECTS));
        for (int i = 0; i < p+1; i++) {
                printf("buffer[%d] = %d\n", i, buffer[i]);
        }

        return 0;
}

/**
 * p must be an array of size 0 ... index
 */
int fillBag(int * p, Object * objects, int index, int objects_n) {
        if (index < 0) {
                return 0;
        }

        if (p[index] == -1) {
                int max = 0;
                for (int i = 0; i < objects_n; i++) {
                        int tmp_weight = index - objects[i].weight;
                        if (tmp_weight >= 0) {
                                int tmp = fillBag(p, objects, index - objects[i].weight, objects_n) + objects[i].value;
                                if (max < tmp) {
                                        max = tmp;
                                }
                        }
                }

                p[index] = max;
        }

        return p[index];
}
