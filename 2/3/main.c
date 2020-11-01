#include <stdio.h>



int main() {
        int n        = 0;
        int nums[10] = {0};
        int repeated = 0;

        scanf("%d", &n);

        while (n > 0) {
                nums[n % 10]++;
                if (nums[n % 10] >= 2) {
                        repeated = 1;
                }
                n /= 10;
        }

        if (repeated) {
                printf("Cifre ripetute:");
                for (int i = 0; i < 10; i++) {
                        if (nums[i] > 1) {
                                printf(" %d", i);
                        }
                }
        } else {
                printf("Non ci sono cifre ripetute");
        }

        return 0;
}
