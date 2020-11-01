#include <stdio.h>
#include <string.h>

int isPalindrome( const char * const str) {
        const char * ptr1 = str;
        const int len     = strlen(str);
        const char * ptr2 = str+len-1;
        int is_pal        = 1;

        for(int i = 0; is_pal && i < len/2; i++) {
                if(*ptr1 != *ptr2) {
                        is_pal = 0;                            
                }

                ptr1++;
                ptr2--;
        }

        return is_pal;
}

int main(int argc, char * args[]) {
        printf("%d", isPalindrome(*(args+1)));
        return 0;
}

