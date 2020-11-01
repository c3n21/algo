#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        int day;
        int month;
        int year;
}Date;

int main(int argc, char * args[]) {
        Date * dates = (Date *) malloc(sizeof(Date)*(argc-1));
        int    size  = 0;
        char * arg   = (char *) malloc(sizeof(char)*5);

        for (int i = 0, br = 0; i < argc-1 && --br; i++) {
                arg[2] = '\0';
                arg[4] = '\0';
                memcpy(arg, *(args+i+1), 2);
                (dates+i)->day = atoi(arg);

                memcpy(arg, *(args+i+1)+3, 2);
                (dates+i)->month = atoi(arg);

                memcpy(arg, *(args+i+1)+6, 4);
                (dates+i)->year = atoi(arg);

                br = (dates+i)->year + (dates+i)->month + (dates+i)->day + 1;

                size++;
        }

        for (int i = 0; i < size-1; i++) {
                printf("%02d/%02d/%04d\n", (dates+i)->day, (dates+i)->month, (dates+i)->year);
        }



        return 0;
}
