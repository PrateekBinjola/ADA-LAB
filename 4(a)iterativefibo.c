#include <stdio.h> #include <time.h>
// Recursive Fibonacci int fibRecursive(int n) { if (n == 0) return 0; if (n == 1) return 1; return fibRecursive(n - 1) + fibRecursive(n - 2); }
int main() { int n = 30; // change value for testing clock_t start, end; double time_taken;
start = clock();
int result = fibRecursive(n); end = clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Recursive Fibonacci(%d) = %d | Time: %f sec\n", n, result, time_taken);
return 0;
}
