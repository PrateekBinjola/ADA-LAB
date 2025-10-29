#include <stdio.h> #include <time.h>
#define MAX 128 // maximum matrix size
// Recursive divide & conquer multiplication
void multiplyDC(int n, int A[MAX][MAX], int B[MAX][MAX], int
C[MAX][MAX],
int rowA, int colA, int rowB, int colB, int rowC, int
colC) {
if (n == 1) {
C[rowC][colC] += A[rowA][colA] * B[rowB][colB];
return; }
int newSize = n / 2;
// C11 = A11*B11 + A12*B21
multiplyDC(newSize, A, B, C, rowA, colA, rowB, colB, rowC,
colC);
multiplyDC(newSize, A, B, C, rowA, colA + newSize, rowB +
newSize, colB, rowC, colC);

// C12 = A11*B12 + A12*B22
multiplyDC(newSize, A, B, C, rowA, colA, rowB, colB +
newSize, rowC, colC + newSize);
multiplyDC(newSize, A, B, C, rowA, colA + newSize, rowB +
newSize, colB + newSize, rowC, colC + newSize);
// C21 = A21*B11 + A22*B21
multiplyDC(newSize, A, B, C, rowA + newSize, colA, rowB,
colB, rowC + newSize, colC);
multiplyDC(newSize, A, B, C, rowA + newSize, colA +
newSize, rowB + newSize, colB, rowC + newSize, colC);
// C22 = A21*B12 + A22*B22
multiplyDC(newSize, A, B, C, rowA + newSize, colA, rowB,
colB + newSize, rowC + newSize, colC + newSize); multiplyDC(newSize, A, B, C, rowA + newSize, colA +
newSize, rowB + newSize, colB + newSize, rowC + newSize,
colC + newSize); }
int main() {
int sizes[] = {2, 4, 8, 16}; // must be powers of 2 int numSizes = sizeof(sizes) / sizeof(sizes[0]);
int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
for (int s = 0; s < numSizes; s++) { int n = sizes[s];
// Fill A and B with values for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++) { A[i][j]=i+j;
B[i][j]=i-j;
C[i][j] = 0; // reset result
}
clock_t start = clock(); multiplyDC(n, A, B, C, 0, 0, 0, 0, 0, 0);
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

printf("Matrix Size: %dx%d | Time Taken: %f seconds (Divide & Conquer)\n", n, n, time_taken);
}
return 0; }
