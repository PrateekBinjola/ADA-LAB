#include <stdio.h> #include <stdlib.h> #include <time.h>
void selectionSort(int arr[], int n) { for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) minIndex = j;
}
int temp = arr[minIndex]; arr[minIndex] = arr[i]; arr[i] = temp;
} }
void generateRandomArray(int arr[], int n) { for (int i = 0; i < n; i++)
arr[i] = rand() % 10000; }
void testSelectionSort(int n) {
int *arr = (int *)malloc(n * sizeof(int)); generateRandomArray(arr, n);
clock_t start, end;

start = clock(); selectionSort(arr, n); end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; printf("Sorted %6d elements in %f seconds.\n", n, time_taken);
free(arr); }
int main() {
printf("Program by: prateek\n"); printf("Roll No: 24293916071\n\n");
int sizes[] = {1000, 5000, 10000, 50000, 100000}; int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
srand(time(NULL));
for (int i = 0; i < num_sizes; i++) { testSelectionSort(sizes[i]);
}
return 0; }
