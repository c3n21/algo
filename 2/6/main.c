#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define PLACEHOLDER '-'

typedef struct {
        int x;
        int y;
} Punto;

int randomChoose(char matrice[10][10], Punto * punti) {
        int i = 3;
        int choices = 4; //numero di direzioni che si possono prendere in via teorica

        do {
                do {
                        i = choices <= 1? 0 : rand() % (choices);
                        printf("[LOOP] i = %d\n", i);
                } while (i == choices);
        
        }while ((matrice[punti[i].y][punti[i].x] != PLACEHOLDER) && --choices > 0);
//                do {
//
//                        printf("[PROBING] choice: y = %d, x = %d, direction: y = %d, x = %d\n", punti[choice].y, punti[choice].x, punti[direction].y, punti[direction].x);
//                        punti[choice] = punti[direction]; //tolgo questo Punto dall'array e lo rimpiazzo con uno ancora valido
//                        printf("[PROBING] direction = %d, choice = %d\n", direction, choice);
//                        printf("[PROBING] punti: y = %d, x = %d, matrice = %c\n", punti[choice].y, punti[choice].x, matrice[punti[choice].y][punti[choice].x]);
//                        printf("[PROBING] m != PLACEHOLDER? %d\n\n", ((matrice[punti[choice].y][punti[choice].x] != PLACEHOLDER)));
//                }while ((matrice[punti[choice].y][punti[choice].x] != PLACEHOLDER) && direction-- > 1);
        return i;
}

int main(int argc, char * args[]) {
        srand(time(NULL));
        char matrice [SIZE][SIZE] = {{PLACEHOLDER}};
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        matrice[i][j] = PLACEHOLDER;                
                }
        }
//        int i = rand() % 10, j = rand() % 10;
        int i = 9, j = 9;

        for (int k = 0; k < 26; k++) {
                printf("[INIT] i = %d, j = %d, char = %c\n", i, j, 'A' + k);
                matrice[i][j] = 'A' + k;
                Punto punti[4]; //genero tutte le combinazioni di spostamenti che posso fare


                punti[0].y = (i-1 >= 0)? i-1: 0; //in alto
                punti[0].x = j;
                printf("[GENERATION] punti[%d].y = %d, punti[%d].x = %d\n", 0, punti[0].y, 0, punti[0].x);

                punti[1].y = i; 
                punti[1].x = (j-1 >= 0)? j-1: 0; //a sinistra
                printf("[GENERATION] punti[%d].y = %d, punti[%d].x = %d\n", 1, punti[1].y, 1, punti[1].x);

                punti[2].y = (i+1 < SIZE)? i+1 : SIZE-1; //in basso
                punti[2].x = j;
                printf("[GENERATION] punti[%d].y = %d, punti[%d].x = %d\n", 2, punti[2].y, 2, punti[2].x);

                punti[3].y = i; 
                punti[3].x = (j+1 < SIZE)? j+1: SIZE-1; //a destra
                printf("[GENERATION] punti[%d].y = %d, punti[%d].x = %d\n", 3, punti[3].y, 3, punti[3].x);

                int choice = randomChoose(matrice, punti);
                printf("[CHOSEN] choice = %d, matrice = %c\n", choice, matrice[punti[choice].y][punti[choice].x]);

                if (matrice[punti[choice].y][punti[choice].x] != PLACEHOLDER) { //se choice è una posizione già occupata vuol dire che anche direction è a 0, e quindi non c'erano altre scelte disponibili
                        k = 26;
                } 
                else {
                        printf("[ASSIGNING] punti: y = %d, x = %d, choice = %d\n\n", punti[choice].y, punti[choice].x, choice);
                        i = punti[choice].y;
                        j = punti[choice].x;
                }
        }

        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                        printf("%c", matrice[i][j]);
                }
                printf("\n");
        }

        return 0;
}
