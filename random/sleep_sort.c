/*
Sleep sort algorithm -- as originally seen on 4chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sleep_sort(int *nums, int size);
// Given: array of integers and length of array
// Prints elements in ascending order

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
        sleep_sort(arr, size);
    }
}

void sleep_sort(int *nums, int size) {
    setvbuf(stdout, NULL, _IONBF, 0); // turn off line buffering

    // Put each number to sleep according to value
    printf("Sorted: {");
    int i;
    for (i = 0; i < size; i++) {
        if (!fork()) { // child process
            sleep(nums[i]);
            printf(" %d ", nums[i]);
            exit(0);
        }
    }

    // Wait for all child processes to finish
    int j;
    for (j = 0; j < size; j++) {
        wait(NULL);
    }
    printf("}\n");
}
