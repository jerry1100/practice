/*
Testing out creating member functions inside structs through the use of function pointers
*/

#include <stdio.h>

int add_numbers(int a, int b);
// Given: two integers
// Returns: their sum

typedef struct Number {
    int (*add)(int a, int b); // function pointer is a member variable
} Number;

int main() {
    int a = 3;
    int b = 4;

    Number num;
    num.add = add_numbers; // assign function to function pointer

    printf("The result of %d + %d is %d\n", a, b, num.add(a, b));
}

int add_numbers(int a, int b) {
    return a + b;
}
