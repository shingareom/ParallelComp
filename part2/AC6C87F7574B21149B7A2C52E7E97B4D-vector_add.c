#include <immintrin.h>   // for AVX intrinsics
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000  // 10 million elements

int main() {
    float *a = aligned_alloc(32, N * sizeof(float));
    float *b = aligned_alloc(32, N * sizeof(float));
    float *c = aligned_alloc(32, N * sizeof(float));

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0f;
        b[i] = i * 2.0f;
    }

    clock_t start = clock();

    // Vectorized addition using AVX
    for (int i = 0; i < N; i += 8) {
        __m256 va = _mm256_load_ps(a + i);   // load 8 floats
        __m256 vb = _mm256_load_ps(b + i);   // load next 8
        __m256 vc = _mm256_add_ps(va, vb);   // add them
        _mm256_store_ps(c + i, vc);          // store result
    }

    clock_t end = clock();

    printf("c[0] = %.2f, c[last] = %.2f\n", c[0], c[N-1]);
    printf("Time taken: %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(a);
    free(b);
    free(c);
    return 0;
}

