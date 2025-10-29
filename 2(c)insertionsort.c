#include <stdio.h> #include <stdlib.h> #include <time.h>
void insertionSort(int arr[], int n) { for (int i = 1; i < n; i++) {
int key = arr[i];
intj=i-1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--; }
arr[j + 1] = key; }
}
void generateRandomArray(int arr[], int n) { for (int i = 0; i < n; i++)
arr[i] = rand() % 10000; }
void testInsertionSort(int n) {
int *arr = (int *)malloc(n * sizeof(int)); generateRandomArray(arr, n);

clock_t start, end; start = clock(); insertionSort(arr, n); end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; printf("Sorted %6d elements in %f seconds.\n", n, time_taken);
free(arr); }
int main() {
printf("Program by: prateek\n"); printf("Roll No: 24293926071\n\n");
int sizes[] = {1000, 5000, 10000, 50000, 100000}; int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
srand(time(NULL));
for (int i = 0; i < num_sizes; i++) { testInsertionSort(sizes[i]);
}
return 0; }
