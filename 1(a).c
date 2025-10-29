// linear_searching.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // found at index i
        }
    }
    return -1;  // not found
}

int main(void) {
    int n, tgt_idx, key;
    clock_t begin, finish;
    double elapsed;
    int repeat = 1000;  // Number of times to repeat the search

    printf("How many numbers do you want in the array? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Please enter a positive integer.\n");
        return 1;
    }

    // dynamically allocate array
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // seed random generator and fill array
    srand((unsigned)time(NULL));
    for (int k = 0; k < n; k++) {
        arr[k] = rand() % (n * 10);
    }

    // set up worst-case scenario
    tgt_idx = n - 1;
    key = arr[tgt_idx];

    // measure execution time by repeating the search
    int pos = -1;
    begin = clock();
    for (int i = 0; i < repeat; i++) {
        pos = linearSearch(arr, n, key);
    }
    finish = clock();
    elapsed = (double)(finish - begin) / CLOCKS_PER_SEC / repeat;

    if (pos >= 0)
        printf("Element %d found at index %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    printf("Average search time: %lf seconds\n", elapsed);

    free(arr);
    return 0;
}
