#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>

int isAnnagramma(char * str1, char * str2) {
        int c [26] = {0};
        int res = 1;

        int len = strlen(str1);

        if (len != strlen(str2)) {
                res = 0;
        }

        for (int i = 0; res && i < len; i++) {
                c[tolower(str1[i]) - 97]++;
                c[tolower(str2[i]) - 97]--;
        }

        for (int i = 0; res && i < 26; i++) {
                if(c[i]) {
                        res = 0;
                }
        }
        
        return res;
}

int main(int argc, char * args[]) {
        
        return isAnnagramma(*(args+1), *(args+2));
}

