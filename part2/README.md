## ⚙️ **Part 2 Folder – `part2/README.md`**
*(Vectorization & AVX Implementation)*

```markdown
# Part 2 – Vectorization and AVX Implementation

This part explores **data-level parallelism** using **Intel AVX (Advanced Vector Extensions)**.  
It demonstrates how vectorized instructions can improve computational performance compared to scalar execution.

---

## 🧩 Objectives
- Implement a program that performs vectorized operations.
- Use **AVX intrinsics** or **compiler auto-vectorization**.
- Measure performance improvements.

---

## ⚙️ Implementation Steps

### 1️⃣ Check CPU AVX Support
```bash
lscpu | grep avx
2️⃣ Write or Compile with Vectorization
Compile with optimization:
gcc -O3 -march=native -ftree-vectorize vectorized_program.c -o vectorized
3️⃣ Run and Compare
Run both versions:
time ./non_vectorized
time ./vectorized
Compare the execution times and note the improvement.

🧮 Example Programs
	•	Vector Addition
	•	Dot Product
	•	Matrix Multiplication (SIMD)
	•	Array Summation

🧠 Analysis
Parameter
Non-Vectorized
Vectorized (AVX)
Execution Time


CPU Utilization


Speedup Factor



📷 Screenshots (Add Yours)
	•	Compilation output
	•	Execution time comparison
	•	CPU capability (lscpu output)

🧾 References
	•	Intel AVX Documentation
	•	Vector Instructions Tutorial – UMass
---

