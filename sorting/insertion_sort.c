/*
Insertion sort algorithm to sort an array of integers
*/

#include <stdio.h>

void insertionSort(int *nums, int size);
// Given: array of integers and length of array
// Array elements will be sorted in ascending order

int main() {
    for (;;) {
        int arr[1000];
        int size = 0;

        // Read in numbers and save to array
        printf("Enter array elements, separate by spaces:\n");
        char ch;
        while (scanf("%d%c", &arr[size++], &ch) && ch != '\n');

        // Unsorted
        printf("\nUnsorted: {");
        int i;
        for (i = 0; i < size; i++) {
            printf(" %d ", arr[i]);
        }
        printf("}\n");

        // Sorted
        insertionSort(arr, size);
        printf("Sorted: {");
        for (i = 0; i < size; i++) {
            printf(" %d ", arr[i]);
        }
        printf("}\n\n");
    }
}

void insertionSort(int *nums, int size) {
    #ifdef DEBUG
    printf("\n**********BEGIN DEBUG**********");
    #endif

    // Loop through elements, starting at position 2
    int i, j;
    for (i = 1; i < size; i++) {
        #ifdef DEBUG
        printf("\nAt position %d, value %d\n", i, nums[i]);
        printf("Old: {");
        int k;
        for (k = 0; k < size; k++) {
            printf(" %d ", nums[k]);
        }
        printf("}\n");
        #endif

        // While current element is less than previous, swap them
        for (j = i; nums[j] < nums[j-1] && j > 0; j--) {
            #ifdef DEBUG
            printf("Swapping %d and %d\n", nums[j], nums[j-1]);
            #endif

            int temp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = temp;
        }

        #ifdef DEBUG
        printf("New: {");
        for (k = 0; k < size; k++) {
            printf(" %d ", nums[k]);
        }
        printf("}\n");
        #endif
    }
    #ifdef DEBUG
    printf("**********END DEBUG**********\n\n");
    #endif
}
