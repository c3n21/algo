#include <stdio.h>
#include <stdlib.h>

#include "libpsgraph.h"

void drawKoch (const char * filename, int x, int i);

void drawKochRecursive(int x, int i);

int main (int argc, char * args[]) {
        printf("%s", (args+1)[0]);
        int x = atoi((args+2)[0]);
        int i = atoi((args+3)[0]);
        printf("x = %d; i = %d", x, i);
        drawKoch((args+1)[0], x, i);
        return 0;
}

//300 120 300
void drawKochRecursive(int x, int i) {
        if (i < 0) {
                printf("ERRORE");
        }

        if (i == 0) {
                draw(x);
        } else {
                double new_length = x/3;
                draw(new_length);
                turn(45);
                drawKochRecursive(new_length, i-1);
                turn(-45);
                drawKochRecursive(new_length, i-1);
        }
}

void drawKoch (const char * filename, int x, int i) {
        start(filename);
        drawKochRecursive(x,i);
        end();
}

