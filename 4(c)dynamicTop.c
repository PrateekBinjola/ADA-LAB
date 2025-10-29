#include <stdio.h> #include <time.h> int memo[1000];
// Initialize memoization table void initMemo() { for (int i = 0; i < 1000; i++) { memo[i] = -1; } }
// Top-Down Fibonacci int fibTopDown(int n) { if (n == 0) return 0; if (n == 1) return 1;
if (memo[n] != -1) return memo[n]; // already computed
memo[n] = fibTopDown(n - 1) + fibTopDown(n - 2); return memo[n];
}
int main() { int n = 30; // change value for testing clock_t start, end; double time_taken;
initMemo();
start = clock();
int result = fibTopDown(n); end = clock();

time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Top-Down DP Fibonacci(%d) = %d | Time: %f sec\n", n, result, time_taken);
return 0; }
