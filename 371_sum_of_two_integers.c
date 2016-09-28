/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

#include <stdio.h>

int getSum(int a, int b);
// Given: two integers
// Returns: the sum of the two integers without using + or - operators

int main() {
    int num1, num2;

    for (;;) {
        printf("Enter two numbers separated by a space: ");
        scanf("%d %d", &num1, &num2);
        printf("The sum of %d and %d is %d\n\n", num1, num2, getSum(num1, num2));
    }
}

int getSum(int a, int b) {
    int sum = 0;
    int carry = 0;

    // Compare bits starting from least significant to most significant
    long int mask;
    for (mask = 1; mask <= 2147483648; mask <<= 1) {
        int bitA = a & mask;
        int bitB = b & mask;

        // Possible combinations
        if (bitA ^ bitB) {
            sum += !carry*mask;
        } else {
            sum += carry*mask;
            carry = (bitA & bitB) ? 1: 0;
        }
    }
    return sum;
}
