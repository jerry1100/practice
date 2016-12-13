/*
A simple decimal to binary converter
*/

#include <stdio.h>
#include <stdlib.h>

char *dec_to_bin(int num);
// Given: an integer
// Returns: a string that is the binary representation of the integer

int main() {
    for (;;) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d in binary is: %s\n\n", num, dec_to_bin(num));
    }
}

char *dec_to_bin(int num) {
    // Find the number of bits needed
    int tmp = num;
    int num_bits;
    for (num_bits = 1; tmp > 1; num_bits++) {
        tmp = tmp >> 1;
    }

    char *bin_str = (char *) malloc((num_bits+1)*sizeof(char));

    // Fill in binary string in reversed order
    int i;
    for (i = num_bits-1; i >= 0; i--) {
        bin_str[i] = num % 2 + '0'; // get char version of num
        num = num >> 1;
    }
    bin_str[num_bits] = '\0';

    return bin_str;
}
