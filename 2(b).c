#include <stdio.h> #include <stdlib.h> #include <time.h>
int partition(int arr[], int low, int high) { int pivot = arr[high];
inti=low-1;
for (int j = low; j < high; j++) {
if (arr[j] <= pivot) { i++;
int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
} }
int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp; return i + 1;
}
void quickSort(int arr[], int low, int high) { if (low < high) {
int pi = partition(arr, low, high); quickSort(arr, low, pi - 1); quickSort(arr, pi + 1, high);
} }
void generateRandomArray(int arr[], int n) { for (int i = 0; i < n; i++)

arr[i] = rand() % 10000; }
void testQuickSort(int n) {
int *arr = (int *)malloc(n * sizeof(int)); generateRandomArray(arr, n);
clock_t start, end; start = clock(); quickSort(arr, 0, n - 1); end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; printf("Sorted %6d elements in %f seconds.\n", n, time_taken);
free(arr); }
int main() {
printf("Program by: prateek\n"); printf("Roll No: XXXXX\n\n");
int sizes[] = {1000, 5000, 10000, 50000, 100000}; int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
srand(time(NULL));
for (int i = 0; i < num_sizes; i++) { testQuickSort(sizes[i]);
}

return 0; }
