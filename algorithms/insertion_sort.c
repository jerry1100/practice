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
        printf("Enter array elements, separate by spaces: ");
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
    int current, i;

    // For each element, insert it in the proper location
    for (current = 1; current < size; current++) {
        // Keep swapping until hit left wall or left num is lesser
        for (i = current; i > 0 && nums[i] < nums[i-1]; i--) {
            int tmp = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = tmp;
        }
    }
}
