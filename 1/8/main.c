#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * args[]) {
        char * a = *(args+1);
        char * b = *(args+2);
        char * str = (char *) malloc(9*sizeof(char));
        

        a[2] = '\0';
        a[5] = '\0';

        b[2] = '\0';
        b[5] = '\0';

        printf("%02d:%02d:%02d", 
                        abs(atoi(a) - atoi(b)), 
                        abs(atoi(a+3) - atoi(b+3)), 
                        abs(atoi(a+6) - atoi(b+6))
                        );

        return 0;
}

/*
 * No perché il numero massimo rappresentabile con due byte (ovvero uno short) è poco più di 65k mentre 24 ore convertiti in secondi sono 86400 se si vuole usare al massimo una variabile short int.
 * Se si possono usare più variabili short int allora è possibile
 */
