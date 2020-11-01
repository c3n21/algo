#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * args[]) {

        (*(args+1))[2] = '\0';

        char * str = args[1];
        str = str + 3;


        int h = atoi(*(args+1));
        
        printf("%d", h%12);
        printf(":%s ", ((*(args+1))+3));

        if(h > 12) {
                printf("PM\n");
        } else {
                printf("AM\n");
        }

        return 0;
}
