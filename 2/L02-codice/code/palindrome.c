#include <stdio.h>
#include <string.h>

int isPalindrome(char * str) {
        int res = 1;
        int len = strlen(str);

        for (int i = 0; i < len && res; i++) {
                if (str[i] != str[len - i - 1]) {
                        res = 0;
                }
        }

        return res;
}

int main(int argc, char * args[]) {
        return isPalindrome(args[1]);
}
