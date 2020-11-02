#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * args[]) {
        int c = 0;

        while ((c = getchar()) != '\n') {
                if (c == ' ') {
                        putchar(8);
                }
                putchar(c);
        }
        putchar(8);

        return 0;
}
