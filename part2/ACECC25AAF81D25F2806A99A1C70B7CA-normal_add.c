#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int main() {
    float *a = malloc(N * sizeof(float));
    float *b = malloc(N * sizeof(float));
    float *c = malloc(N * sizeof(float));

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0f;
        b[i] = i * 2.0f;
    }

    clock_t start = clock();

    // Normal scalar addition
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    clock_t end = clock();

    printf("Time taken: %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(a);
    free(b);
    free(c);
    return 0;
}

