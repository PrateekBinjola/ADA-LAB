#include <stdio.h> #include <time.h>
#define MAX 512 // maximum size (must be power of 2)
// Add two matrices
void add(int n, int A[MAX][MAX], int B[MAX][MAX], int
C[MAX][MAX],
int aRow, int aCol, int bRow, int bCol, int cRow, int cCol) {
for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
C[cRow + i][cCol + j] = A[aRow + i][aCol + j] + B[bRow + i][bCol + j];
}
// Subtract two matrices
void subtract(int n, int A[MAX][MAX], int B[MAX][MAX], int
C[MAX][MAX],
int aRow, int aCol, int bRow, int bCol, int cRow, int cCol) {
for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
C[cRow + i][cCol + j] = A[aRow + i][aCol + j] - B[bRow + i][bCol + j];
}
// Strassen multiplication

void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
int aRow, int aCol, int bRow, int bCol, int cRow, int cCol) {
if (n == 1) {
C[cRow][cCol] += A[aRow][aCol] * B[bRow][bCol];
return; }
int mid = n / 2;
int M1[MAX][MAX] = {0}, M2[MAX][MAX] = {0},
M3[MAX][MAX] = {0}, M4[MAX][MAX] = {0}; int M5[MAX][MAX] = {0}, M6[MAX][MAX] = {0},
M7[MAX][MAX] = {0};
int T1[MAX][MAX] = {0}, T2[MAX][MAX] = {0};
// M1 = (A11 + A22) * (B11 + B22)
add(mid, A, A, T1, aRow, aCol, aRow + mid, aCol + mid, 0, 0); add(mid, B, B, T2, bRow, bCol, bRow + mid, bCol + mid, 0, 0); strassen(mid, T1, T2, M1, 0, 0, 0, 0, 0, 0);
// M2 = (A21 + A22) * B11
add(mid, A, A, T1, aRow + mid, aCol, aRow + mid, aCol + mid,
0, 0);
strassen(mid, T1, B, M2, 0, 0, bRow, bCol, 0, 0);
// M3 = A11 * (B12 - B22)
subtract(mid, B, B, T1, bRow, bCol + mid, bRow + mid, bCol
+ mid, 0, 0);
strassen(mid, A, T1, M3, aRow, aCol, 0, 0, 0, 0);
// M4 = A22 * (B21 - B11)
subtract(mid, B, B, T1, bRow + mid, bCol, bRow, bCol, 0, 0); strassen(mid, A, T1, M4, aRow + mid, aCol + mid, 0, 0, 0, 0);
// M5 = (A11 + A12) * B22
add(mid, A, A, T1, aRow, aCol, aRow, aCol + mid, 0, 0); strassen(mid, T1, B, M5, 0, 0, bRow + mid, bCol + mid, 0, 0);
// M6 = (A21 - A11) * (B11 + B12)
subtract(mid, A, A, T1, aRow + mid, aCol, aRow, aCol, 0, 0); add(mid, B, B, T2, bRow, bCol, bRow, bCol + mid, 0, 0); strassen(mid, T1, T2, M6, 0, 0, 0, 0, 0, 0);

// M7 = (A12 - A22) * (B21 + B22)
subtract(mid, A, A, T1, aRow, aCol + mid, aRow + mid, aCol +
mid, 0, 0);
add(mid, B, B, T2, bRow + mid, bCol, bRow + mid, bCol +
mid, 0, 0);
strassen(mid, T1, T2, M7, 0, 0, 0, 0, 0, 0);
// C11 = M1 + M4 - M5 + M7 for (int i = 0; i < mid; i++)
for (int j = 0; j < mid; j++)
C[cRow + i][cCol + j] = M1[i][j] + M4[i][j] - M5[i][j] +
M7[i][j];
// C12 = M3 + M5
for (int i = 0; i < mid; i++)
for (int j = 0; j < mid; j++)
C[cRow + i][cCol + j + mid] = M3[i][j] + M5[i][j];
// C21 = M2 + M4
for (int i = 0; i < mid; i++)
for (int j = 0; j < mid; j++)
C[cRow + i + mid][cCol + j] = M2[i][j] + M4[i][j];
// C22 = M1 - M2 + M3 + M6 for (int i = 0; i < mid; i++)
for (int j = 0; j < mid; j++)
C[cRow + i + mid][cCol + j + mid] = M1[i][j] - M2[i][j] +
M3[i][j] + M6[i][j]; }
int main() {
int sizes[] = {64, 128, 256}; // Strassen works best with
power of 2
int numSizes = sizeof(sizes) / sizeof(sizes[0]);
for (int s = 0; s < numSizes; s++) {
int n = sizes[s];
int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
// Fill matrices
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { A[i][j]=i+j; B[i][j]=i-j;

C[i][j] = 0; }
}
clock_t start = clock(); strassen(n, A, B, C, 0, 0, 0, 0, 0, 0);
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Matrix Size: %dx%d | Time Taken: %f seconds (Strassen)\n", n, n, time_taken);
}
return 0; }
