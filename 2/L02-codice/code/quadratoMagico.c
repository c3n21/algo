#include <stdio.h>

#define SIZE 3

int main() {
        int n = SIZE, nn = 0;
//        int quadrato[n][n] = {{0}}, k = 1;
        int quadrato[SIZE][SIZE] = {{0}}, k = 1;
        int i, j, inew, jnew;

        i = 0; j = n/2;
        nn = n * n;
        for ( k = 1; k <= nn; k++ ) {
                quadrato[i][j] = k;
                inew = ( i == 0 ) ? n - 1 : i - 1;
                jnew = ( j == n - 1 ) ? 0 : j + 1;
                if ( quadrato[ inew ][ jnew ] == 0 ) {
                        i = inew;
                        j = jnew;
                }
                else {
                        i++; 
                }
        }

        int sum_diagonale1      = 0;
        int sum_diagonale2      = 0;
        int sum_colonne [SIZE] = {0};

        for (int i = 0, j = 0; i < SIZE; i++) {
                int sum = 0;
                for (j = 0; j < SIZE; j++) {
                        if (i == j) {
                                sum_diagonale1 += quadrato[i][j];
                        }

                        if (j == SIZE - i - 1) {
                                sum_diagonale2 += quadrato[i][j];
                        }

                        sum_colonne[j] += quadrato[i][j];
                        sum += quadrato[i][j];

                        printf("%d ", quadrato[i][j]);
                }
                printf("sum = %d\n", sum);
                if (i == SIZE - 1) {
                        for (j = 0; j < SIZE; j++) {
                                printf("%d ", sum_colonne[j]);
                        }
                        printf("\n");
                }
        }

        printf("sum_diagonale1 = %d\n", sum_diagonale1);
        printf("sum_diagonale2 = %d", sum_diagonale2);
        
        return 0;
}

/*
 * [1] Deve essere un intero perché viene usato anche come indice per la matrice, e NON può essere inserito dall'utente
 * [2] Viene usata per rappresentare i numeri da 1 fino a n^2
 * [3] Viene assegnato n-1 se i == 0, altrimenti i-1 e serve per cambiare la riga del quadrato in cui inserire k
 * [7] Si parte mettendo il numero 1 al centro della prima riga, e poi si va sempre in alto a destra di un quadrato (eventualmente ricominciando dall'altro capo del quadrato quando si giunge al limite in altezza o lunghezza). Ogni volta che si trova una casella occupata si va giù di un quadrato rispetto alla posizione corrente, per poi ripetere la stessa transizione fino a quando si raggiunge n^2
 * [8] La somma di tutti i numeri deve essere n(n^2 + 1)/2
 */
