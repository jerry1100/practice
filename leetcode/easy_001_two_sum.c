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

}

int *twoSum(int *nums, int numsSize, int target) {
    int i, j;
    for (i = 0; i < numsSize-1; i++) {
        for (j = i+1; j < numsSize; j++) {
            if (nums[i][j] == target) {
                
            }
        }
    }
}
