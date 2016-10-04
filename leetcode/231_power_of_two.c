/*
Given an integer, write a function to determine if it is a power of two.
*/

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n);
// Given: an integer
// Returns: true if the integer is a power of two, false otherwise

int main() {
    int num;
    for (;;) {
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%sa power of two\n", isPowerOfTwo(num) ? "Is " : "Is not ");
    }
}

bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    
    // Check for only one 1 in binary representation
    int bit = 0;
    int mask;
    for (mask = 1; mask > 0; mask <<= 1) {

        // Retrieve bit and remove it from original
        if (bit = n & mask) {
            n -= bit;
            break;
        }
    }

    return bit && !n; // true if retrieved bit was the only bit
}
