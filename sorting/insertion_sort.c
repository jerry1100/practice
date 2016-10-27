/*
Insertion sort algorithm to sort an array of integers
*/

#include <stdio.h>
#include <stdlib.h>

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
        printf("Unsorted: {");
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
    int i, j;
    for (i = 1; i < size; i++) { // go through elements, starting at second
        for (j = i; nums[j] < nums[j-1] && j > 0; j--) { // find correct spot
            int temp = nums[j]; // swap elements
            nums[j] = nums[j-1];
            nums[j-1] = temp;
        }
    }
}
