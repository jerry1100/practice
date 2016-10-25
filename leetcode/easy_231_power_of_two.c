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
    
    // Get the first 1 from binary representation
    int mask = 1;
    int bit;
    do {
        bit = n & mask;
        n -= bit; // subtracting bit should be 0 if the bit was the only one
        mask = mask << 1;
    } while (!bit);

    return bit && !n; // true if retrieved bit was the only bit
}
