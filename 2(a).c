#include <stdio.h> #include <stdlib.h> #include <time.h>
void merge(int arr[], int left, int mid, int right) { intn1=mid-left+1;
int n2 = right - mid;
int *L = (int *)malloc(n1 * sizeof(int)); int *R = (int *)malloc(n2 * sizeof(int));
for (int i = 0; i < n1; i++) L[i] = arr[left + i];
for (int j = 0; j < n2; j++) R[j]=arr[mid+1+j];
int i = 0, j = 0, k = left; while(i<n1&&j<n2){
if (L[i] <= R[j]) arr[k++] = L[i++];
else
arr[k++] = R[j++];
}
while (i < n1) arr[k++] = L[i++];

while (j < n2) arr[k++] = R[j++];
free(L);
free(R); }
void mergeSort(int arr[], int left, int right) { if (left < right) {
int mid = left + (right - left) / 2; mergeSort(arr, left, mid); mergeSort(arr, mid + 1, right); merge(arr, left, mid, right);
} }
void generateRandomArray(int arr[], int n) { for (int i = 0; i < n; i++)
arr[i] = rand() % 10000; }
void testMergeSort(int n) {
int *arr = (int *)malloc(n * sizeof(int)); generateRandomArray(arr, n);
clock_t start, end;
start = clock(); mergeSort(arr, 0, n - 1); end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

printf("Sorted %6d elements in %f seconds.\n", n, time_taken);
free(arr); }
int main() {
printf("Program by: prateek\n"); printf("Roll No: XXXXX\n\n");
int sizes[] = {1000, 5000, 10000, 50000, 100000}; int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
srand(time(NULL));
for (int i = 0; i < num_sizes; i++) { testMergeSort(sizes[i]);
}
return 0; }
