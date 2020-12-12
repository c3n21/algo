#include <stdio.h>
#define max(a,b) \
        ({ __typeof__ (a) _a = (a); \
         __typeof__ (b) _b = (b); \
         _a > _b ? _a : _b; })

typedef struct s_intervallo {
        int i;
        int f;
        int v;
} Intervallo;

void printIntervalli(Intervallo * intervalli, int size);
void init(Intervallo * intervalli, int size);
int scheduling(Intervallo * input, int *,int *, int j);
int p(Intervallo * input, int * states, int j);
void sort(Intervallo * input, int size);


int main() {
        int size;
        scanf("%d", &size);

        Intervallo intervalli[size+1];
        int soluzione[size];
        int states[size];

        for (int i = 0; i < size; i++) {
                soluzione[i] = -1;
                states[i]    = -1;
        }

        init(intervalli, size);
        printIntervalli(intervalli, size);
        printf("A' SORR'TING\n");
        sort(intervalli, size);
        printIntervalli(intervalli, size);

        printf("max = %d \n", scheduling(intervalli, soluzione, states, size));

        int res = p(intervalli, states, size);
        for (int i = 0; i < size; i++) {
                printf("soluzione[%d] = %d\n",i, soluzione[i]);
        }

        for (int i = 0; i < size; i++) {
                printf("states[%d] = %d\n",i, states[i]);
        }

        while (res != 0) {
                printf("res = %d, i = %d, f = %d, v = %d\n", res, intervalli[res-1].i, intervalli[res-1].f, intervalli[res-1].v);
                res = p(intervalli, states, res);
        }
        printf("res = %d\n", res);

        return 0;
}

void printIntervalli(Intervallo * intervalli, int size) {
        for (int i = 0; i < size; i++) {
                printf("i = %d, f = %d, v = %d\n", intervalli[i].i, intervalli[i].f, intervalli[i].v);
        }
}

void init(Intervallo * intervalli, int size) {
        for (int i = 0; i < size; i++) {
                scanf("%d", &intervalli[i].i);
                scanf("%d", &intervalli[i].f);
                scanf("%d", &intervalli[i].v);
        }
}

int scheduling(Intervallo * input, int * soluzione, int * states, int j) {
        int k = j-1;

        if (k < 0) {
                return 0;
        }

        if (soluzione[k] == -1) {
                soluzione[k] = max(input[k].v + scheduling(input, soluzione, states, p(input, states, j)-1), 
                                scheduling(input, soluzione, states, j-1));
        }

        return soluzione[k];
}

void sort(Intervallo * input, int size) {
        int swapped = 1;

        while (swapped) {
                swapped = 0;
                for (int i = 0; i < size-1; i++) {
                        int j = i+1;
                        if (input[i].f > input[j].f) {
                                swapped = 1;
                                Intervallo tmp = input[i];
                                input[i] = input[j];
                                input[j] = tmp;
                        }
                }
                size--;
        }
}


/**
 * restituisce indice dell'ultimo intervallo utile
 *
 * j >= 1
 * input[0] -> j == 1
 *
 */
int p(Intervallo * input, int * states, int j) {
        int k = j-1; //normalizzo k
        if (k < 0) {
                return 0;
        }

        if (k == 0) {
                states[k] = 0; //corrispondente a input[0]
        }

        if (states[k] == -1) { //non calcolato, k > 0
                Intervallo curr = input[k]; //cerco il primo intervallo precedente a k
                for (int i = k-1; i > 0; i--) {
                        if (curr.i >= input[i].f) {
                                states[k] = i; //primo con intervallo che non interseca
                                break;
                        }
                }
        }

        return states[k] + 1;
}
