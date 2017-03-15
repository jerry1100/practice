/*
Bubble sort algorithm to sort an array of integers
*/

#include <stdio.h>

void bubble_sort(int *nums, int size);
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
        bubble_sort(arr, size);
        printf("Sorted: {");
        for (i = 0; i < size; i++) {
            printf(" %d ", arr[i]);
        }
        printf("}\n\n");
    }
}

void bubble_sort(int *nums, int size) {
    int end, i;

    // Traverse array and float highest values to the top
    for (end = size-1; end > 0; end--) {
        // Find highest values
        for (i = 0; i < end; i++) {
            if (nums[i] > nums[i+1]) {
                int tmp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = tmp;
            }
        }
    }
}
