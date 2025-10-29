#include <stdio.h> #include <time.h>
// Bottom-Up Fibonacci int fibBottomUp(int n) { if (n == 0) return 0; int fib[n + 1]; fib[0] = 0; fib[1] = 1; for (int i = 2; i <= n; i++) { fib[i] = fib[i - 1] + fib[i - 2]; } return fib[n]; }
int main() { int n = 30; // change value for testing clock_t start, end; double time_taken;
start = clock();
int result = fibBottomUp(n); end = clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Bottom-Up DP Fibonacci(%d) = %d | Time: %f sec\n", n, result, time_taken);
return 0;
}
