#include <stdio.h>

#include <math.h>

#define true 1
#define false 0

int main() {
    unsigned long int n = 1;
    unsigned long int m = 1;
    unsigned long int k = 1;
    unsigned long int l = 1;

    while (true) { 
        m = pow(2, pow(2, n)) + 1;

        for (k = 2; k * k < m; k++) {
            if (m % k == 0) {
                l = m/k;

                printf("Found! m = %ld, k = %ld, l = %ld e n = %ld\n", m, k, l, n);

                break;
            }
        }

        if (n % 1000000 == 0)
            printf("Current guess is %ld!\n", n);

        n++;
    }

    return 0;
}
