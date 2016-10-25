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
    for (;;) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);

        printf("%d is %sa power of 4\n", num, isPowerOfFour(num) ? "" : "not ");
    }
}

bool isPowerOfFour(int num) {
    if (num < 1) return false;
    
    // Get first 1 from binary representation
    int mask = 1;
    int bit;
    do {
        bit = num & mask;
        num -= bit; // subtracting bit should be 0 if the bit was the only one
        mask = mask << 2;
    } while (!bit && mask > 0); // stop at first bit received or overflow

    return bit && !num; // true if retrieved bit was the only bit
}
