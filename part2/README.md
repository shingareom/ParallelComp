# SPEED DEMON AVX VS NORMAL CODE

Yo, check this.. I made this little program that shows how to make your code go BRRRR by using your CPU's secret parallel powers.

## What this thing does:

It adds two giant arrays (like 10 MILLION numbers each) in two different ways:

**The Slow Way (normal code):**
```cpp
// One by one... so boring
for (int i = 0; i < size; i++) {
    c[i] = a[i] + b[i];
}
```

**The Fast Way (AVX black magic):**
```cpp
// EIGHT numbers at once! YEAH!
__m256 va = _mm256_loadu_ps(&a[i]);  // Grab 8 numbers
__m256 vb = _mm256_loadu_ps(&b[i]);  // Grab 8 more  
__m256 vc = _mm256_add_ps(va, vb);   // Add ALL of them in one go
_mm256_storeu_ps(&c[i], vc);         // Spit out 8 results
```

## How to run this bad boy:

```bash
# Build it
g++ vectorization_avx.cpp -o vectorization_avx -mavx -O2 # this is overpowered by the -02, you can remove it to see the real power of the AVX

# Run it and watch the magic
./vectorization_avx
```

## What you'll probably see:

```
Scalar Time     : 42 ms    
AVX Time        : 11 ms    
Speedup (x)     : 3.81x    
Result Verified : Yes      
```

Translation: The AVX version is like 4x faster because it does 8 math problems at the same time instead of one by one. Pretty sick, right?

## The techy stuff (if you care):

- AVX = Advanced Vector Extensions = your CPU's built-in parallel math superpowers
- Those `__m256` things are like special 256-bit wide registers that can hold 8 floats
- It's like having 8 math calculators working simultaneously instead of one

## Wanna see if your CPU can do this?

```bash
lscpu | grep avx
```

If it says "avx" anywhere, you're good to go.
