/*
Selection sort algorithm to sort an array of integers
*/

#include <stdio.h>

void selectionSort(int *nums, int size);
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
        selectionSort(arr, size);
        printf("Sorted: {");
        for (i = 0; i < size; i++) {
            printf(" %d ", arr[i]);
        }
        printf("}\n\n");
    }
}

void selectionSort(int *nums, int size) {
    int current, i;

    // For each element, replace it with the minimum of the rest of elements
    for (current = 0; current < size-1; current++) {
        int minIndex = current;
        int minValue = nums[current];

        for (i = current+1; i < size; i++) { // find minimum value
            if (nums[i] < minValue) {
                minIndex = i;
                minValue = nums[i];
            }
        }

        nums[minIndex] = nums[current]; // swap minimum and current
        nums[current] = minValue;
    }
}
