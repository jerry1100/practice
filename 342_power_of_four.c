/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int num);
// Given: a signed 32 bit integer
// Returns: whether it is a power of 4

int main() {
    int i;
    for (i = 0; i < 0b1111111111111111111111111111111; i++) {
        if (isPowerOfFour(i)) {
            printf("%d is a power of four\n", i);
        }
    }
}

bool isPowerOfFour(int num) {
    switch (num) { // test individually for powers of 4
        case 0b00000000000000000000000000000001:
        case 0b00000000000000000000000000000100:
        case 0b00000000000000000000000000010000:
        case 0b00000000000000000000000001000000:
        case 0b00000000000000000000000100000000:
        case 0b00000000000000000000010000000000:
        case 0b00000000000000000001000000000000:
        case 0b00000000000000000100000000000000:
        case 0b00000000000000010000000000000000:
        case 0b00000000000001000000000000000000:
        case 0b00000000000100000000000000000000:
        case 0b00000000010000000000000000000000:
        case 0b00000001000000000000000000000000:
        case 0b00000100000000000000000000000000:
        case 0b00010000000000000000000000000000:
        case 0b01000000000000000000000000000000: return true;
        default: return false;
    }
}
