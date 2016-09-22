/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <stdio.h>

int singleNumber(int *nums, int numsSize);
// Given: an array of integers where every integer occurs twice except one and the size of the array
// Return: the integer that occurs only once

int main() 
{
    int numArray[] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    printf("The single number is %d\n", singleNumber(numArray, 11));
}

int singleNumber(int *nums, int numsSize)
{
    int result = 0;

    // XOR all numbers, erasing duplicates and leaving the single number
    int i;
    for (i = 0; i < numsSize; i++)
    {
        result ^= *(nums+i);
    }

    return result;
}
