#include <immintrin.h>   
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;
using namespace std::chrono;

void scalar_addition(const float* a, const float* b, float* c, int size) {
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }
}


void avx_addition(const float* a, const float* b, float* c, int size) {
    int i = 0;
     for (; i + 8 <= size; i += 8) {
        __m256 va = _mm256_loadu_ps(&a[i]);
        __m256 vb = _mm256_loadu_ps(&b[i]);
        __m256 vc = _mm256_add_ps(va, vb);
        _mm256_storeu_ps(&c[i], vc);
    }
     for (; i < size; i++) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    const int SIZE = 10000000; 
    float* A = new float[SIZE];
    float* B = new float[SIZE];
    float* C_scalar = new float[SIZE];
    float* C_avx = new float[SIZE];

    // Initialize data
    for (int i = 0; i < SIZE; i++) {
        A[i] = sin(i) * 0.5f;
        B[i] = cos(i) * 0.5f;
    }

    cout << "-------------------------------\n";
    cout << "   VECTORIZATION USING AVX\n";
    cout << "-------------------------------\n";
    cout << "Array Size: " << SIZE << " elements\n\n";

    // ---------------- Scalar Execution ----------------
    auto start_scalar = high_resolution_clock::now();
    scalar_addition(A, B, C_scalar, SIZE);
    auto end_scalar = high_resolution_clock::now();
    auto scalar_time = duration_cast<milliseconds>(end_scalar - start_scalar).count();

    // ---------------- AVX Vectorized Execution ----------------
    auto start_avx = high_resolution_clock::now();
    avx_addition(A, B, C_avx, SIZE);
    auto end_avx = high_resolution_clock::now();
    auto avx_time = duration_cast<milliseconds>(end_avx - start_avx).count();

    // ---------------- Verify correctness ----------------
    bool correct = true;
    for (int i = 0; i < 10; i++) {
        if (fabs(C_scalar[i] - C_avx[i]) > 1e-6) {
            correct = false;
            break;
        }
    }

    // ---------------- Results ----------------
    cout << fixed << setprecision(6);
    cout << "Scalar Time     : " << scalar_time << " ms\n";
    cout << "AVX Time        : " << avx_time << " ms\n";
    cout << "Speedup (x)     : " << (double)scalar_time / avx_time << "x\n";
    cout << "Result Verified : " << (correct ? "Yes" : "No") << "\n";

    cout << "\nSample Results (First 8 elements):\n";
    for (int i = 0; i < 8; i++) {
        cout << "A[" << i << "] + B[" << i << "] = "
             << C_scalar[i] << endl;
    }

    cout << "\nAVX vectorization complete.\n";
    cout << "You can verify CPU support using:  lscpu | grep avx\n";

    delete[] A;
    delete[] B;
    delete[] C_scalar;
    delete[] C_avx;
    return 0;
}
