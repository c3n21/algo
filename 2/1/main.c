/*
 * Pre-programma
 * [1] No non è necessario memorizzare l'intera frase di input, mi basta leggere un carattere alla volta e fare le elaborazioni necessarie al momento
 * [2] È da memorizzare invece l'occorrenza di un carattere che si può fare con un comunissimo array
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define N_ALPHABET 26
#define OFFEST 97

int main (int argc, char* args[]) {
        unsigned int values [N_ALPHABET];
        int len      = strlen (*(args+1));
        
        for (int i = 0; i < N_ALPHABET; i++) {
                values[i] = 0;
        }

        for (int i = 0; i < len; i++) {
                int c = tolower ((*(args+1))[i]) - OFFEST;
                values[c]++;
        }

        for (int i = 0; i < N_ALPHABET; i++) {
                printf ("%c ", i + OFFEST);

                for (int j = 0; j < values[i]; j++) {
                        printf("*");       
                }
                printf("\n");
        }

      return 0;
}
