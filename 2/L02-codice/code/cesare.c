#include <stdio.h>

int main() {
        char testo [1024];
        int c = 0;
        int i = 0;

        while ((c = getchar()) != '.') {
                testo[i] = c;
                i++;
        };
        testo[i] = '\0';

        scanf("%d", &c);

        for(i = 0; testo[i] != '\0'; i++) {
                //printf("%c", testo[i] + c);
                putchar(testo[i] + c);
        }

        return 0;
}
//comportamento strano: getchar prende anche i newline
