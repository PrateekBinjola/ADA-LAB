#include <stdlib.h>
#include <time.h>
void bubbleSort(int arr[], int n) { for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) { if (arr[j] > arr[j + 1]) {
int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
} }
} }
void generateRandomArray(int arr[], int n) { for (int i = 0; i < n; i++)
arr[i] = rand() % 10000; }
int main() {
printf("Program by: prateek\n"); printf("Roll No: 24293916071\n\n");
int sizes[] = {1000, 5000, 10000, 50000, 100000}; for (int s = 0; s < 5; s++) {
int n = sizes[s];

int *arr = (int *)malloc(n * sizeof(int)); generateRandomArray(arr, n);
clock_t start = clock(); bubbleSort(arr, n); clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; printf("Sorted %6d elements in %f seconds.\n", n, time_taken);
free(arr); }
return 0; }
