#include <stdio.h> #include <stdlib.h> #include <time.h>
// ---------- Utility functions ----------
void generateMatrix(int n, int mat[n][n]) {
for(int i=0; i<n; i++) for(int j=0; j<n; j++)
mat[i][j] = rand() % 10; }
void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) { for(int i=0; i<n; i++)
for(int j=0; j<n; j++) C[i][j] = A[i][j] + B[i][j];
}
void subMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) { for(int i=0; i<n; i++)
for(int j=0; j<n; j++) C[i][j] = A[i][j] - B[i][j];
}
// ---------- (a) Iterative ----------
void multiplyIterative(int n, int A[n][n], int B[n][n], int C[n][n]) {
for(int i=0; i<n; i++) { for(int j=0; j<n; j++) {
C[i][j] = 0;
for(int k=0; k<n; k++) {
C[i][j] += A[i][k] * B[k][j]; }
} }
}
// ---------- (b) Recursive ----------

void multiplyRecursive(int n, int A[n][n], int B[n][n], int C[n][n]) { if(n==1){
C[0][0] = A[0][0] * B[0][0];
return; }
int k = n/2;
int A11[k][k], A12[k][k], A21[k][k], A22[k][k]; int B11[k][k], B12[k][k], B21[k][k], B22[k][k]; int C11[k][k], C12[k][k], C21[k][k], C22[k][k]; int M1[k][k], M2[k][k];
// Split
for(int i=0; i<k; i++) {
for(int j=0; j<k; j++) { A11[i][j] = A[i][j]; A12[i][j] = A[i][j+k]; A21[i][j] = A[i+k][j]; A22[i][j] = A[i+k][j+k];
B11[i][j] = B[i][j]; B12[i][j] = B[i][j+k]; B21[i][j] = B[i+k][j]; B22[i][j] = B[i+k][j+k];
} }
// C11 = A11*B11 + A12*B21 multiplyRecursive(k, A11, B11, M1); multiplyRecursive(k, A12, B21, M2); addMatrix(k, M1, M2, C11);
// C12 = A11*B12 + A12*B22 multiplyRecursive(k, A11, B12, M1); multiplyRecursive(k, A12, B22, M2); addMatrix(k, M1, M2, C12);
// C21 = A21*B11 + A22*B21 multiplyRecursive(k, A21, B11, M1); multiplyRecursive(k, A22, B21, M2); addMatrix(k, M1, M2, C21);
// C22 = A21*B12 + A22*B22

multiplyRecursive(k, A21, B12, M1); multiplyRecursive(k, A22, B22, M2); addMatrix(k, M1, M2, C22);
// Combine
for(int i=0; i<k; i++) {
for(int j=0; j<k; j++) { C[i][j] = C11[i][j]; C[i][j+k] =C12[i][j]; C[i+k][j] =C21[i][j]; C[i+k][j+k] = C22[i][j];
} }
}
// ---------- (c) Strassen ----------
void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
if(n==1){
C[0][0] = A[0][0] * B[0][0]; return;
}
int k = n/2;
int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
int C11[k][k], C12[k][k], C21[k][k], C22[k][k];
int M1[k][k], M2[k][k], M3[k][k], M4[k][k], M5[k][k], M6[k][k],
M7[k][k];
int T1[k][k], T2[k][k];
// Split
for(int i=0; i<k; i++) {
for(int j=0; j<k; j++) { A11[i][j] = A[i][j]; A12[i][j] = A[i][j+k]; A21[i][j] = A[i+k][j]; A22[i][j] = A[i+k][j+k];
B11[i][j] = B[i][j]; B12[i][j] = B[i][j+k]; B21[i][j] = B[i+k][j]; B22[i][j] = B[i+k][j+k];
}

}
// Strassen formulas
addMatrix(k, A11, A22, T1); addMatrix(k, B11, B22, T2); strassen(k, T1, T2, M1);
addMatrix(k, A21, A22, T1); strassen(k, T1, B11, M2);
subMatrix(k, B12, B22, T2); strassen(k, A11, T2, M3);
subMatrix(k, B21, B11, T2); strassen(k, A22, T2, M4);
addMatrix(k, A11, A12, T1); strassen(k, T1, B22, M5);
subMatrix(k, A21, A11, T1); addMatrix(k, B11, B12, T2); strassen(k, T1,
T2, M6);
subMatrix(k, A12, A22, T1); addMatrix(k, B21, B22, T2); strassen(k, T1,
T2, M7);
// Combine results
addMatrix(k, M1, M4, T1); subMatrix(k, T1, M5, T2); addMatrix(k, T2, M7, C11);
addMatrix(k, M3, M5, C12);
addMatrix(k, M2, M4, C21);
subMatrix(k, M1, M2, T1); addMatrix(k, T1, M3, T2); addMatrix(k, T2,
M6, C22);
for(int i=0; i<k; i++) { for(int j=0; j<k; j++) { C[i][j] = C11[i][j];
C[i][j+k] =C12[i][j]; C[i+k][j] =C21[i][j]; C[i+k][j+k] = C22[i][j];
} }
}
// ---------- Main driver ---------- int main() {
int n;
printf("Enter matrix size (power of 2): "); scanf("%d", &n);
int A[n][n], B[n][n], C[n][n]; generateMatrix(n, A); generateMatrix(n, B);
// Iterative

clock_t start = clock();
multiplyIterative(n, A, B, C);
clock_t end = clock();
double t_iter = (double)(end - start) / CLOCKS_PER_SEC;
// Recursive
start = clock();
multiplyRecursive(n, A, B, C);
end = clock();
double t_rec = (double)(end - start) / CLOCKS_PER_SEC;
// Strassen
start = clock();
strassen(n, A, B, C);
end = clock();
double t_strassen = (double)(end - start) / CLOCKS_PER_SEC;
printf("\n=== Execution Time Comparison (n=%d) ===\n", n); printf("Iterative: %f seconds\n", t_iter);
printf("Recursive: %f seconds\n", t_rec);
printf("Strassen : %f seconds\n", t_strassen);
return 0; }
