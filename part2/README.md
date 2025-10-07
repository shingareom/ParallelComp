# Part 2 – Vectorization and AVX Implementation

This part explores **data-level parallelism** using **Intel AVX (Advanced Vector Extensions)**.  
It demonstrates how vectorized instructions can improve computational performance compared to scalar execution.

---

## Objectives
- Implement a program that performs vectorized operations.
- Use **AVX intrinsics** or **compiler auto-vectorization**.
- Measure performance improvements.

---

## Implementation Steps

### Check CPU AVX Support
```bash
lscpu | grep avx
```
### Write or Compile with Vectorization, Compile with optimization:

```bash
gcc -O3 -march=native -ftree-vectorize vectorized_program.c -o vectorized
```
### Run and Compare
Run both versions:

```bash
time ./non_vectorized
time ./vectorized
```
Compare the execution times and note the improvement.

Example Programs
- Vector Addition
- Dot Product
Matrix Multiplication (SIMD)
Array Summation
