/*
Selection sort algorithm to sort an array of integers
*/

#include <stdio.h>

void selection_sort(int *nums, int size);
// Given: array of integers and length of array
// Array elements will be sorted in ascending order

int main() {
    for (;;) {
        int arr[1000];
        int size = 0;

        // Keep reading until the end of line
        printf("Enter array elements, separate by spaces: ");
        char ch;
        while (scanf("%d%c", &arr[size++], &ch), ch != '\n');

        // Unsorted
        printf("Unsorted: {");
        int i;
        for (i = 0; i < size; i++) {
            printf(" %d ", arr[i]);
        }
        printf("}\n");

        // Sorted
        selection_sort(arr, size);
        printf("Sorted: {");
        for (i = 0; i < size; i++) {
            printf(" %d ", arr[i]);
        }
        printf("}\n\n");
    }
}

void selection_sort(int *nums, int size) {
    int current, i;

    // For each element, replace it with the minimum of the rest of elements
    for (current = 0; current < size-1; current++) {
        int min_index = current;
        int min_value = nums[current];

        for (i = current+1; i < size; i++) { // find minimum value
            if (nums[i] < min_value) {
                min_index = i;
                min_value = nums[i];
            }
        }

        nums[min_index] = nums[current]; // swap minimum and current
        nums[current] = min_value;
    }
}
