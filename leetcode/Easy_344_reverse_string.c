/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

#include <stdio.h>

char *reverseString(char *s);
// Given: a pointer to a char string
// Returns: a pointer to the reversed char string

int main() {
    char str[] = "0123456789";

    printf("Before: %s\n", str);
    printf("After: %s\n", reverseString(str));
}

char* reverseString(char* s) {
    if (!s || !*s) return s; // handle bad input

    char *head = s;
    char *tail = s;
    while (*(tail+1) != '\0') tail++; // pointer to end of string
   
    // Reorder string
    while (head < tail) {
        char tmp = *head;
        *head = *tail;
        *tail = tmp;

        head++;
        tail--;
    }

    return s;
}
