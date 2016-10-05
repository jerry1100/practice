/*
Insertion sort algorithm to sort an array of integers
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *nums, int size);
// Given: array of integers and length of array
// Array elements will be sorted in ascending order

// First parameter: size of randomly generated array
// Second parameter: 1 to display array contents, 0 to suppress
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: 2 arguments needed, %d given\n", argc-1);
        return -1;
    }

    srand(time(NULL));
    int size = atoi(argv[1]);
    int display = atoi(argv[2]);
    int numArr[size];
    int i;

    // Populate array with random numbers 1 - 100
    for (i = 0; i < size; i++) {
        numArr[i] = rand() % 100 + 1;
    }

    // Unsorted
    if (display) {
        printf("Before:\t[ ");
        for (i = 0; i < size; i++) {
            printf("%d ", numArr[i]);
        }
        printf("]\n\n");
    }

    // Measure runtime
    clock_t clk = clock();
    insertionSort(numArr, size);
    clk = clock() - clk;

    // Sorted
    if (display) {
        printf("After:\t[ ");
        for (i = 0; i < size; i++) {
            printf("%d ", numArr[i]);
        }
        printf("]\n");
    }

    printf("Process took %li clock cycles\n", clk);
}

void insertionSort(int *nums, int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        for (j = i; nums[j] < nums[j-1] && j > 0; j--) {
            int temp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = temp;
        }
    }
}
