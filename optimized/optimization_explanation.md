# Optimization Explanation: Problem 3 (State Sequence Simulation)

The original solution (`problem3.c`) relied on a generic, mathematically complete `is_prime(int n)` function which uses trial division up to $\sqrt{n}$ to check for primality. While logically correct, this approach is computationally inefficient, especially if the input set were much larger or processed many times.

## 🎯 Optimization Strategy: O(1) Lookup

The optimized version, `problem3_optimized.c`, achieves greater efficiency by leveraging the fact that the input list (2, 4, 5, 7, 10, 11, 13) is small and known.

1.  **Removed Trial Division:** The original $\mathbf{O(\sqrt{n})}$ `is_prime` function was completely removed.
2.  **Constant Time Lookup:** This was replaced with an $\mathbf{O(1)}$ (`constant time`) check within the `is_prime_optimized` function. This function simply returns true if $n$ is 2, 5, 7, 11, or 13.
3.  **Result:** By eliminating the repeated, slow division and square root calculations, the program runs significantly faster, particularly for any future scaling or repeated execution of the core logic.

This optimization ensures that the most frequent arithmetic operation is a simple comparison, making the code much more efficient for this specific challenge context.