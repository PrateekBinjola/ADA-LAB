// Binary_Searching.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary search function
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, key;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // Fill array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    // Sort before binary search
    qsort(arr, n, sizeof(int), cmpfunc);

    key = arr[n - 1];  // search last element (worst case)

    start = clock();
    for (int i = 0; i < 100000; i++) {
        binarySearch(arr, n, key);
    }
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("n = %d, Time taken = %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
