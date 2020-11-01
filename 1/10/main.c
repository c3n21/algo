#include <stdio.h>

int main ( int argc, char * args[] ) {

        int day   = 0;
        int month = 0;

        scanf("%d %d", &day, &month);


        if(
                        month == 1 || 
                        month == 3 || 
                        month == 5 || 
                        month == 7 || 
                        month == 8 || 
                        month == 10 || 
                        month == 12) {
                month = 31;
        } else {
                month = 30;
        }

        if(month == 2) {
                month = 28; //febbraio ha 28 giorni
        }
        //      0 2 4 6 8 10 12
        printf("L M M G V S D\n"); //13 chars

        day = (day<<1) -2;
        for(int i = 1; i <= month;) {
                for(int j = 0; j < 13; j = j+2) {
                        if(j >= day) {
                                printf("%d ", i++);
                        } else {
                                printf("  ");
                        }
                }
                printf("\n");
                day = 0;
        }

        return 0;
}
