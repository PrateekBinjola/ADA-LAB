#include <stdio.h> #include <time.h>
// Iterative Fibonacci int fibIterative(int n) { if (n == 0) return 0; int a = 0, b = 1, c; for (int i = 2; i <= n; i++) { c = a + b; a = b; b = c; } return b; }
int main() { int n = 30; // change value for testing clock_t start, end; double time_taken;

start = clock();
int result = fibIterative(n); end = clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Iterative Fibonacci(%d) = %d | Time: %f sec\n", n, result, time_taken);
return 0;
}
