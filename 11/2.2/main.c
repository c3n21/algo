#include <stdio.h>

typedef struct s_types {
        int weight;
        int value;
} Item;

int fillBag(int P, Item * items, int m, int buffer[P+1][m+1]);

int main() {
        int P; //peso supportato dallo zaino
        int m; //numero di item

        scanf("%d", &P);
        scanf("%d", &m);

        Item items[m];

        for (int i = 0; i < m && 
                        scanf("%d", &items[i].weight) != EOF && 
                        scanf("%d", &items[i].value) != EOF; i++);

        printf("Portata zaino = %d\n", P);
        for (int i = 0; i < m; i++) {
                printf("objects[%d].weight = %d, value = %d\n", i, items[i].weight, items[i].value);
        }

        int buffer[P+1][m+1];

        printf("Valore ottimale = %d\n", fillBag(P, items, m, buffer));

        for (int i = 0; i < P+1; i++) {
                for (int j = 0; j < m+1; j++) {
                        printf("%d ", buffer[i][j]);
                }
                printf("\n");
        }

        return 0;
}

int fillBagAlgorithm(int P, Item *items, int m, int buffer[P+1][m+1]) { //primi m oggetti
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < P+1; j++) {
                        Item item = items[i];
                        if (buffer[j][i] > buffer[j][i+1]) { //propagazione
                                buffer[j][i+1] = buffer[j][i];
                        
                        }


                        int t_jweight = j - item.weight;
                        if (t_jweight >= 0 && (buffer[t_jweight][i] + item.value) > buffer[j][i+1]) {//ci sta, quindi lo aggiungo
                                buffer[j][i+1] = buffer[t_jweight][i] + item.value;//prendo il valore migliore con uno zaino senza questo elemento
                                if (buffer[j][i+1] < item.value) {
                                        buffer[j][i+1] = item.value;
                                }
                        } 
                }
        }

        return buffer[P][m];
}

int fillBag(int P, Item * items, int m, int buffer[P+1][m+1]) {
        for (int i = 0; i < P+1; i++) {
                for (int j = 0; j < m+1; j++) {
                        if (i == 0 || j == 0) {
                                buffer[i][j] = 0;
                        } else {
                                buffer[i][j] = -1;
                        }
                }
        }

        return fillBagAlgorithm(P, items, m, buffer);
}
