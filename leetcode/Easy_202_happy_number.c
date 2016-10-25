/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include <stdio.h>
#include <stdbool.h>

bool isHappy(int n);
// Given: an integer
// Returns: true if the integer is a happy number, false otherwise

int sumDigitsSquared(int n);
// Given: an integer
// Returns: the sum of the integer's digits squared

int main() {
    int num;

    for (;;) {
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is%sa happy number\n\n", num, isHappy(num) ? " " : " not ");
    }
}

bool isHappy(int n) {
    if (n < 0) return false; // happy numbers are not negative

    int fast = n;
    int slow = n;

    // Floyd's Cycle Detection - if fast meets slow, then it is a cycle
    do {
        slow = sumDigitsSquared(slow); // go forward one step
        fast = sumDigitsSquared(sumDigitsSquared(fast)); // go forward two steps
    } while (fast != 1 && fast != slow);
    
    return (fast == 1);
}

int sumDigitsSquared(int n) {
    int sum = 0;

    // Get each digit, square it, and add to sum
    while (n) {
        int digit = n % 10;
        n /= 10;
        sum += digit*digit;
    }

    return sum;
}
