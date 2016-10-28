/*
Performance test that compares runtimes for different sorting algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *nums, int size);
// Given: array of integers and length of array
// Array elements will be sorted in ascending order

int main() {
    srand(time(NULL)); // use time to randomize

    for (;;) {
        // Get number of random array elements to generate
        int size;
        printf("\nEnter the number of random array elements to generate: ");
        while (scanf("%d", &size) != 1) {
            while (getchar() != '\n'); // flush buffer
            printf("Invalid input! Enter number of elements: ");
        }
        while (getchar() != '\n'); // flush buffer

        // Populate array with random numbers
        int arr[size];
        int i;
        for (i = 0; i < size; i++) {
            arr[size] = rand() % 100 + 1; // random number 1 - 100

            #ifdef DEBUG
            printf("Element %d has value %d\n", i, arr[size]);
            #endif
        }

        // Get command
        char cmd;
        clock_t clk;
        printf("Test (i)nsertion, (q)uick, (m)erge: ");
        while (scanf("%c", &cmd) != 1) {
            while (getchar() != '\n'); // flush buffer
            printf("Invalid input! Enter a valid command: ");
        }
        while (getchar() != '\n'); // flush buffer

        // Process command
        // NOTE: CLOCK CYCLE COUNT IS UNRELIABLE
        switch (cmd) {
            case 'i':
                clk = clock();
                insertionSort(arr, size);
                clk = clock() - clk;
                printf("Insertion sort took %li clock cycles\n", clk);
                break;
            case 'q':
                clk = clock();
                //quickSort();
                clk = clock() - clk;
                printf("Quick sort took %li clock cycles\n", clk);
                break;
            case 'm':
                clk = clock();
                //mergeSort();
                clk = clock() - clk;
                printf("Merge sort took %li clock cycles\n", clk);
                break;
            default:
                printf("Invalid choice, restarting program\n");
                break;
       }
    }
}

void insertionSort(int *nums, int size) {
    // Loop through elements, starting at position 2
    int i, j;
    for (i = 1; i < size; i++) {
        // While current element is less than previous, swap them
        for (j = i; nums[j] < nums[j-1] && j > 0; j--) {
            int temp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = temp;
        }
    }
}
