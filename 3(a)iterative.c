#include <stdio.h>
#include <time.h>
int main() {
int sizes[] = {100, 200, 300, 400, 500}; // matrix sizes to test int numSizes = sizeof(sizes) / sizeof(sizes[0]);
for(ints=0;s<numSizes;s++){ int n = sizes[s];
int A[n][n], B[n][n], C[n][n];
// Fill A and B with simple values for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { A[i][j]=i+j;
B[i][j]=i-j; }
}
iterative

// Start time
clock_t start = clock();
// Matrix multiplication (iterative) for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { C[i][j] = 0;
for (int k = 0; k < n; k++) {
C[i][j] += A[i][k] * B[k][j]; }
} }
// End time
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Matrix Size: %dx%d | Time Taken: %f seconds\n", n, n, time_taken);
}
return 0; }
