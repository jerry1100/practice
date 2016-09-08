#include <stdio.h>

char *reverseString(char *s);
// Given: a pointer to a char string
// Returns: a pointer to the reversed char string

int main()
{
    // Before
    char str[] = "0123456789";
    int i = 0;
    while (str[i] != '\0') putchar(str[i++]);
    putchar('\n');

    // After
    char *revStr = reverseString(str);
    while (*revStr != '\0') putchar(*revStr++);
    putchar('\n');
}

char* reverseString(char* s)
{
    if (!s || !*s) return s; // handle bad input

    char *head = s;
    char *tail = s;
    while (*(tail+1) != '\0') tail++; // pointer to end of string
   
    // Reorder string
    while (head < tail)
    {
        //printf("Swapping head: %c, tail: %c\n", *head, *tail);
        char tmp = *head;
        *head = *tail;
        *tail = tmp;

        head++;
        tail--;
    }

    return s;
}
