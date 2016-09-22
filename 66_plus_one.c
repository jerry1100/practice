/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int digitsSize, int *returnSize);
// Given: a non-negative number represented as an array of digits
// Returns: add one to the number and return the result as an array of digits

int main() {
    int num1[] = {0, 2, 3, 4, 5, 6, 7};
    int num2[] = {9, 9, 9, 9, 9, 9, 9};
    int i;
    int size;
    int *out;

    // Test case 1
    printf("Input:\t[ ");
    for (i = 0; i < 7; i++ ) {
        printf("%d ", num1[i]);
    }
    printf("]\n");
    out = plusOne(num1, 7, &size);
    printf("Output:\t[ ");
    for (i = 0; i < size; i++ ) {
        printf("%d ", *(out+i));
    }
    printf("]\n\n");

    // Test case 2
    printf("Input:\t[ ");
    for (i = 0; i < 7; i++ ) {
        printf("%d ", num2[i]);
    }
    printf("]\n");
    out = plusOne(num2, 7, &size);
    printf("Output:\t[ ");
    for (i = 0; i < size; i++ ) {
        printf("%d ", *(out+i));
    }
    printf("]\n");
}

int *plusOne(int *digits, int digitsSize, int *returnSize) {
    int *arrHead = (int *) malloc((digitsSize+1)*(sizeof(int))); // allocate n+1 integer slots
    int *arrTail = arrHead + digitsSize;
    int *tail = digits + digitsSize - 1;

    int i; 
    int carry = 1;
    for (i = 0; i < digitsSize; i++) { // copy from end to beginning
        
        *(arrTail-i) = *(tail-i) + carry;
        if (*(arrTail-i) > 9) { // if carry, then copy a 0
            *(arrTail-i) = 0;
            carry = 1;
        } else { // not carry, copy the digit
            carry = 0;
        }
    }
    if (carry) { // if carry remaining, then carry over to very front

        *arrHead = 1;
        *returnSize = digitsSize+1;
        return arrHead;
    }
    *returnSize = digitsSize;
    return arrHead+1;
}
