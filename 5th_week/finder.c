#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define LIMIT      1000
#define EXAMPLE    5777
#define ITERATIONS 54

typedef enum boolean {false, true} bool;

void sieve_e (bool primes[], int size) {
    int i, j;

    for (i = 2; i * i < size; i++) {
        if (primes[i]) {
            for (j = i * i; j < size; j += i) {
                primes[j] = false; 
            }
        }
    }
}

int main() {
    int i, j;
    bool primes[LIMIT] = {[0 ... LIMIT - 1] = true};

    bool found = false;

    int count = 0;

    sieve_e(primes, LIMIT);

    for (i = 2; i < LIMIT && !found && count < ITERATIONS; i++) {
        /* not a prime number, go away */
        if (!primes[i]) {
            continue;
        }

        count++;

        for (j = 1; 2 * j * j + i <= EXAMPLE && !found; j++) {
            if ((2 * j * j) + i == EXAMPLE) {
                printf("Found! a = %d, b = %d and a + b * b * 2 = %d\n", 
                        i, j, (2 * j * j) + i);

                found = true;
            }
        }

        printf("Testing for a = %d and b = 1 ... %d\n", i, j - 1);
    }

    if (!found) {
        printf("Could not be found!\n");
    }

    return 0;
}
