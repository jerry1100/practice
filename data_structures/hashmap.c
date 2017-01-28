/*
A hashmap implementation in C using the 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    Node *next;
} Node;

unsigned long hash(unsigned char *str);
// Given: a string
// Returns: the hash of the string

int main() {
    for (;;) {
        char *line = NULL;
        size_t len = 0;

        // Get line fron user input
        printf("Enter a string to hash: ");
        getline(&line, &len, stdin);

        // Display results
        printf("The resulting hash is: %lu\n\n", hash(line));
        free(line);
    }
}

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}
