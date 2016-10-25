/*
Given a non negative integer number num. For every numbers i in the range 0  i  num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include <stdio.h>
#include <stdlib.h>

int *countBits(int num, int *returnSize);
// Given: two integers
// Returns: an array and saves the size of the array in returnSize

int main() {
    for (;;) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);

        int size;
        int *arr = countBits(num, &size);

        int i;
        for (i = 0; i < size; i++) {
            if ((i & (i-1)) == 0) { // every power of 2 is a new section
                printf("\n[%d]", i);
            }
            printf(" %d ", arr[i]);
        }
        printf("\n\n");
    }
}

int *countBits(int num, int *returnSize) {
    int *arr = (int *) malloc((num+1)*(sizeof(int)));
    *returnSize = num+1;

    arr[0] = 0;
    int counter = 1; // keep track of where in the pattern to copy from
    int i;
    for (i = 1; i <= num; i++) {
        if ((i & (i-1)) == 0) { // check if power of 2
            arr[i] = 1;
            counter = 1; // start of a new section, go back to pattern start
        } else {
            arr[i] = arr[counter] + 1; // add one to pattern for new pattern
            counter++;
        }
    }

    return arr;
}
