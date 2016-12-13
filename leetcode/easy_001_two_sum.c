/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target);
// Given: pointer to array, size of array, and target integer
// Returns: indices of array elements that add up to target integer

int main() {
    for (;;) {
        int arr[1000];
        int size = 0;
        int target;

        // Keep reading until the end of line
        printf("Enter target then numbers, separated by spaces: ");
        scanf("%d", &target);
        char ch;
        while (scanf("%d%c", &arr[size++], &ch) && ch != '\n');

        // Print result
        int *result = twoSum(arr, size, target);
        printf("Target: %d\n", target);
        printf("Index1: %d, value: %d\n", result[0], arr[result[0]]);
        printf("Index2: %d, value: %d\n", result[1], arr[result[1]]);
    }
}

int *twoSum(int *nums, int numsSize, int target) {
    int i, j;
    for (i = 0; i < numsSize-1; i++) {
        for (j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *result = (int *) malloc(2*sizeof(int));
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
}
